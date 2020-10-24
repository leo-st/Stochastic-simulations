#ifdef _WIN32
	#define _CRT_SECURE_NO_DEPRECATE
#endif
#define Nw 64000
// Standardne ANSI-C++ biblioteke
//  - nisu potrebne sve biblioteke za ovaj primjer,
//    ali su dodane radi jedostavnije prilagodne primjera
//    za demonstraciju drugih problema
#include <stdio.h>   // standardne ulazno, izlazne funkcije
#include <stdlib.h>  // standardne C-funkcije
#include <math.h>    // potrebne matematicke funkcije

#include "ran1.c" // ucitavamo datoteku u kojoj je definiran generator

int main(void) {
	int i;
	float r;
	long idum = (-2578); // RAN: generatoru u pocetku prosljedjujemo negativni cijeli broj
	FILE  *fin,*fout2;
	double dx=2;
	double P[81]={0};

	fout2 = fopen("razdioba2.dat","w");
	float temp;
	//generiranje nasumicnih polozaja
	int Nk=501;
	int k=1;
	int w=1;
	float x[Nw+1]={0.0};
	int Nwtemp;
	for(k=1;k<=Nk;k++){

		for(i=0;i<81;i++){
			P[i]=0;
		}
		Nwtemp=0;
		for(w=1;w<Nw;w++){
			r = ran1(&idum);
			temp=x[w]+r*6-3;
			if(temp>-80 && temp<80){
				x[w]=temp;
				i=(int)((x[w]+80)/dx);
				//printf("%d\n", i);
				P[i]+=1;
			}
			else{
				x[w]=temp;
			}
		}
		if(k==100 || k==200 || k==300 || k==400){
			for(i=0;i<81;i++){
				P[i]=P[i]/Nw;
				fprintf(fout2,"%lf\t%lf\n" ,i*dx-80, P[i]/dx );

			}

		}


	}
	fclose(fout2);


	return 0;
}
