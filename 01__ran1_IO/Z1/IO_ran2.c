#ifdef _WIN32
	#define _CRT_SECURE_NO_DEPRECATE
#endif

// Standardne ANSI-C++ biblioteke
//  - nisu potrebne sve biblioteke za ovaj primjer,
//    ali su dodane radi jedostavnije prilagodne primjera
//    za demonstraciju drugih problema
#include <stdio.h>   // standardne ulazno, izlazne funkcije
#include <stdlib.h>  // standardne C-funkcije
#include <math.h>    // potrebne matematicke funkcije

#include "ran1.c" // ucitavamo datoteku u kojoj je definiran generator

int main(void) {
	int i; float r;
	double sum1=0.0;
	double sum2=0.0;
	double a=0.0;
	double b=0.0;
	long idum = (-2578); // RAN: generatoru u pocetku prosljedjujemo negativni cijeli broj
	FILE  *fin, *fout;

	fout = fopen("IO_ran2.txt", "w"); // datoteka za pohranu
	for (i = 1; i <= 5000000; i++) {
		r = ran1(&idum);  // RAN: pozivamo gnereator i pohranjujemo generirani broj u varijablu r
		//ispis u datoteku
		sum1=sum1+pow(r,2);
		sum2=sum2+pow(r,5);
		if(i%1000==0){
			a= fabs(sum1/i-1.0/3.0)*sqrt(i*1.0);
			b= fabs((sum2/i)-(1.0/6.0))*sqrt(i);
			fprintf(fout, "%7d  %13.8e	%13.8e\n", i, a, b);
		}
	}
	fclose(fout);

	
	return 0;
}
