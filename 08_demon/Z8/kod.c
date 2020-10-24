#include <stdio.h>
#include<math.h>

#include "ran1.c"
double E(double v){
    return (pow(v,2))/2.0;
}

int main(){
    double ES=20.0;
    double ED=0.0;
    double sES=0.0, sED=0.0;
    int N=100, Nb=100;
    float r;
    long idum = (-2578);
    int k=10000,i,ip,b;
    double v[N];
    double dvMax=2.0,dv,vTmp, dE, SbE, sKE,sKE1,SbE1;
    int idm=800, id;
    float DIS_ED[idm], dED=100;

    FILE *fout, *fout1,*fp;
    fout=fopen("demon.dat", "w");
    fout1=fopen("demon1.dat", "w");
    fp=fopen("distribucija.dat", "w");

    for(id=0;id<idm;id++) DIS_ED[id]=0.;

    for(i=0;i<N;i++){
        v[i]=sqrt((2*ES)/N);
    }
    SbE=0;
    for(b=0;b<Nb;b++){
        sKE=0;
        sKE1=0.0;
        for(i=0;i<k;i++){
            ip=(int)(ran1(&idum)*N);
            if(ip==N){
                ip=N-1;
            }
            dv = (2.*ran1(&idum)-1.)*dvMax;
            vTmp = v[ip] + dv;
            dE=E(vTmp)-E(v[ip]);

            if(ED>=dE) {
                ED = ED - dE;
                ES = ES + dE;
                v[ip]=vTmp;
            }
            id = (int)(ED*dED);
            if(id<idm) DIS_ED[id]=DIS_ED[id]+1.;
            else printf ("skip ED: %d\t%f\n", id, ED);
            sKE=sKE+ES;
            sKE1=sKE1+ED;



        }

        SbE=SbE+sKE/k;
        SbE1=SbE1+sKE1/k;
        printf("%d\n",b);
        fprintf(fout, "%d\t%lf\t%lf\n",(b+1)*k, sKE/k, SbE/(b+1));
        fprintf(fout1, "%d\t%lf\t%lf\n",(b+1)*k, sKE1/k, SbE1/(b+1));



    }
    for(id=0;id<idm;id++) fprintf(fp,"%f\t%f\n", (float)id/dED, DIS_ED[id]/(k*Nb)*dED);



    fclose(fout);
    fclose(fout1);
    fclose(fp);



    return 0;
}


