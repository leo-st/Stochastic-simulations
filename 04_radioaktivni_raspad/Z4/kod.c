#include <stdio.h>
#include "ran1.c"

int main(){
    FILE *fout;
    fout=fopen("raspad.dat", "w");
    int i;

    long idum=(-2578);
    float r;


    float tmax=20.0;
    int N=5000;
    int Nt;
    float dt=0.083;
    float t=0.0;

    float lambda = 0.277259;
    float p = dt*lambda;

    fprintf(fout, "%lf\t%d\n",t,N );
    while(t<tmax){
        Nt=N;
        for(i=0;i<N;i++){
            r = ran1(&idum);
            if(r<p){
                Nt=Nt-1;
            }
        }
        N=Nt;
        fprintf(fout, "%lf\t%d\n",t,N );

        t=t+dt;
    }
    fclose(fout);
    return 0;
}
