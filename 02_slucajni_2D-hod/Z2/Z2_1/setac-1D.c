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
	long idum = (-2578); // RAN: generatoru u pocetku prosljedjujemo negativni cijeli broj
	FILE  *fin, *fout;
	int Nw=1000;
	int Nk=1000;
	int k=1;
	int w=1;
	int x[1001]={0};
	float Sx2;
    fout = fopen("setac-1D.txt", "w"); // datoteka za pohranu
	for(k=1;k<=Nk;k++){
		Sx2=0;
		for(w=1;w<=Nw;w++){
			r=ran1(&idum);
			if(r<0.5){
				x[w]+=-1;
			}
			else{
				x[w]+=1;
			}
			Sx2+=x[w]*x[w];
		}
		fprintf(fout, "%5d  %13.8e\n", k, Sx2/Nw);
	}
	fclose(fout);

	// provjera zapisanih vrijednosti

	return 0;
}

