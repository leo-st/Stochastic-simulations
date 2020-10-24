#ifdef _WIN32
	#define _CRT_SECURE_NO_DEPRECATE
#endif
#define Nw 250000
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
	FILE  *fin, *fout, *fout1, *fout2, *fout3;
	int j;
	double S;
	double dx=2, dy=2;
	double P[51][51];
	for(i=0;i<51;i++){
		for(j=0;j<51;j++){
			P[i][j]=0;
		}
	}

	fout = fopen("IO_ran1.txt", "w"); // datoteka za pohranu
	fout1 = fopen("razdioba.dat","w");
	fout2 = fopen("razdioba2.dat","w");
	fout3 = fopen("entropija.dat","w");
	float temp;
	//generiranje nasumicnih polozaja
	int Nk=5000;
	int k=1;
	int w=1;
	float x[Nw+1];
	float y[Nw+1];
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

		for(i=0;i<51;i++){
			for(j=0;j<51;j++){
				P[i][j]=0;
			}
		}
		S=0;
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
			i=(int)(x[w]/dx);
			j=(int)(y[w]/dy);
			P[i][j]+=1;



			//if(w==1 || w==5 || w==9)
			//fprintf(fout,"%lf\t%lf\t",x[w], y[w]);
		}
		for(i=0;i<51;i++){
				for(j=0;j<51;j++){
					P[i][j]=P[i][j]/Nw;
					//fprintf(fout2,"%lf\t%lf\t%lf\n" ,i*dx, j*dy, P[i][j]/(dx*dy) );
					if(P[i][j]!=0){
						S=S-P[i][j]*log(P[i][j]);
					}
				}
			}
		fprintf(fout3,"%d\t%lf\n",k, S);

	}
	fclose(fout2);
	fclose(fout1);
	fclose(fout);


	return 0;
}
