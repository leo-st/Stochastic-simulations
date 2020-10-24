#include <stdio.h>
#include <math.h>
#define x 100
#define t 250
#define D 0.01
int main(){
    printf("proslo");
    double broj_intervala_t=1000;

    double broj_intervala_x=500;

    double dt, dx;
    dt=0.5;
    dx=0.2;

    int i,j;
    double rho[x];
    double rho1[x];
    FILE *fout;
    fout=fopen("gustoca.dat","w");

    for(i=0;i<x;i++){
        if(i*dx>=2 && i*dx<=5){
            rho[i]=5.5;
        }
        else{
            rho[i]=0;
        }

    }
    printf("proslo");
    for(j=0;j<t;j++){
        for(i=1;i<x-1;i++){
        rho1[i]=rho[i]+D*dt/(dx*dx)*(rho[i+1]+rho[i-1]-2*rho[i]);
        if(j==50 || j==100 || j==150 || j==200){
            fprintf(fout, "%lf\t%lf\n", i*dx, rho1[i]);
        }

        }
        for(i=0;i<x;i++){
            rho[i]=rho1[i];
        }
        rho[0]=0;
        rho[x-1]=0;

    }



    fclose(fout);

    return 0;

}
