#include <stdio.h>
#include <math.h>

#include "ran1.c"
#define n 400000
double Gfun();
int main(){
    double G;
    double I=0.0;
    double I2=0;
    double var;

    double r,g,f;
    long idum=(-5341);
    int i;
    for (i=0;i<n;i++){
        r = ran1(&idum);
        g=Gfun(r);
        f = (exp((-1)*pow(g,2))/(exp(1.0)/(exp(1.0)-1)*exp(-g)));
        I=I+f;
        I2 = I2 + f*f;
    }
    I=I/n;
    I2=I2/n;
    var = I2 - I*I;
    printf("%lf\n", I);
    printf("%lf\n", sqrt(var));
    printf("%lf\n", sqrt(var)/sqrt(n));



    return 0;
}

double Gfun(double u){
    return -log(1.0-u*((exp(1.0)-1.0)/exp(1.0)));
}
