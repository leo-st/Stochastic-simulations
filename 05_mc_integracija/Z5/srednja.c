#include <stdio.h>
#include <math.h>

#include "ran1.c"
#define n 5000000

int main(){
    double F;
    double a=0,b=1;
    double dx=1.0/n;
    double f=0.0;
    int i;
    long idum=(-5341);
    double r;
    double var=0;
    for(i=1;i<=n;i++){
        r = ran1(&idum);
        f=f+ exp((-1)*pow(r,2));
    }
    F=f/n;
    f=0.0;

    for(i=1;i<=n;i++){
        r = ran1(&idum);
        var = var+pow((exp((-1)*pow(r,2))-F),2);
    }
    var=var/(n-1);
    var = sqrt(var);

    printf("%lf\n", F);
    printf("%lf\n", var);
    printf("%lf\n", var/sqrt(n));



    return 0;
}
