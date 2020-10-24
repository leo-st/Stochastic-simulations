#include <stdio.h>
#include "ran1.c"
#include <math.h>

int main(){
    //file
    FILE *fout,*fout2, *fout3;
    fout=fopen("raspad.dat", "w");
    fout2 = fopen("analiticka1.dat","w");
    fout3 = fopen("analiticka2.dat","w");
    int i;
    int Ntemp;
    //random
    long idum=(-2578);
    float r;


    float tmax =20.0;
    float t=0.0;
    float dt = 0.083;
    //antonima
    int Ns=10000;
    int N1;


    //telurij
    int Nt=0;
    int N2;

    //vjerojatnost
    float lambdas = 0.277259;
    float ps = dt*lambdas;

    float lambdat = 0.0554518;
    float pt= dt*lambdat;



    //glavni dio
    fprintf(fout, "%lf\t%d\t%d\n",t ,Ns ,Nt);
    while(t<tmax){
        Ntemp=Ns;
        for(i=0;i<Ns;i++){
            r = ran1(&idum);
            if(r<ps){
                Ntemp=Ntemp-1;
                Nt++;
            }
        }
        N1=(int)10000*exp((-1.0)*lambdas*t);
        fprintf(fout2, "%lf\t%d\n", t, N1);
        Ns=Ntemp;

        Ntemp = Nt;
        for(i=0;i<Nt;i++){
            r = ran1(&idum);
            if(r<pt){
                Ntemp=Ntemp-1;
            }
        }
        Nt=Ntemp;
        fprintf(fout, "%lf\t%d\t%d\n",t,Ns,Nt );
        N2=(int)10000*(lambdas/(lambdat-lambdas))*(exp((-1.0)*lambdas*t)-exp((-1.0)*lambdat*t));
        fprintf(fout3, "%lf\t%d\n", t, N2);
        t=t+dt;
    }
    fclose(fout);
    fclose(fout2);
    fclose(fout3);
    return 0;
}
