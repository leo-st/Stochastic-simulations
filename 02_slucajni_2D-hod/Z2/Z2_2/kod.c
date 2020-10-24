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

	fout = fopen("IO_ran1.txt", "w"); // datoteka za pohranu
	float temp;
	//generiranje nasumicnih polozaja
	int Nw=5000;
	int Nk=5000;
	int k=1;
	int w=1;
	float x[5001];
	float y[5001];
	x[0]=0;
	y[0]=0;
	for(w=1;w<=Nw;w++){
		r = ran1(&idum);
		x[w]= r*20 + 40;
		r = ran1(&idum);
		y[w]= r*10 + 15;
	}
	for(k=1;k<=Nk;k++){
            fprintf(fout,"\n%d\t",k);
		for(w=1;w<Nw;w++){
			r = ran1(&idum);
            temp=x[w]+r-0.5;
            if(temp > 100){
                x[w]=200-temp;
            }
			else if(temp<0){
				x[w]=temp*(-1);
			}
            else{
                x[w]=temp;
            }
			r=ran1(&idum);
            temp=y[w]+3*r-1.5;
            if(temp > 100){
                y[w]=200-temp;
            }
			else if(temp<0){
				y[w]=temp*(-1);
			}
            else{
                y[w]=temp;
            }
			if(w==1 || w==5 || w==9)
			fprintf(fout,"%lf\t%lf\t",x[w], y[w]);
		}
		

	}

	fclose(fout);


	return 0;
}
