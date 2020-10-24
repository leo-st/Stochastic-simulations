#include <stdio.h>
#include <math.h>
#define x 81
#define t 500
#define D 1.5
int main(){
    double broj_intervala_t=1000;

    double broj_intervala_x=500;

    double dt, dx, S;
    dt=1;
    dx=2;

    int i,j;
    double rho[x];
    double rho1[x];
    FILE *fout;
    fout=fopen("difuzijska1.dat","w");
    //postavaljanje pocetnih uvjeta
    for(i=0;i<x;i++){
        if(i*dx -80 == 0){
            rho[i]=1;
        }
        else{
            rho[i]=0;
        }
    }
    rho[0]=0;
    rho[x-1]=0;
    rho1[0]=0;
    rho1[x-1]=0;
    for(j=1;j<t;j++){       //j=1 jer pocetni trenutak j=0 je gore definiran
        if(j==100 || j==200 || j==300 || j==400) fprintf(fout, "%lf\t%lf\n", i*dx-80, rho[0]/2);
        for(i=1;i<x-1;i++){
            rho1[i]=rho[i]+D*dt/(dx*dx)*(rho[i+1]+rho[i-1]-2*rho[i]);
            if(j==100 || j==200 || j==300 || j==400) fprintf(fout, "%lf\t%lf\n", i*dx-80, rho[i]/2);
        }
        if(j==100 || j==200 || j==300 || j==400) fprintf(fout, "%lf\t%lf\n", i*dx-80, rho[x-1]/2);
        S=0;
        for(i=0;i<x;i++){
            rho[i]=rho1[i];
            S=S+rho[i];
        }
        printf("norm u %d = %f\n",j,S);
    }
    fclose(fout);
    return 0;
}
