#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *dat,*fout;
    char tekst[500];
    double temp,sum,sum2,uksum,uksum2;
    int temp1,temp2;
    double E[1000], sigma[200];
    int i,g,j,k,br;
    int Nb=1000;

    dat = fopen("E.dat","r");

    for(i=0;i<1000;i++){
        fscanf(dat, " %d %lf %lf %lf ",&temp1,&E[i],&temp,&temp);
        //(printf("%d\t%lf\n",i,E[i]);
    }
    for(g=1;g<=Nb/5;g++){
        uksum2=0.0;
        uksum=0.0;
        br=0;
        for(j=0;j<Nb;j=j+g){
                sum=0;
                if(j+g>Nb){
                    break;
                }

            for(k=j;k<j+g;k++){

                sum=sum+E[k];
                if(g==25 && k>960){
                    printf("\n 2 %d\t%d\t%lf\n",j,k,E[k]);
                }
            }
            sum=sum/g;
            sum2=sum*sum;
            uksum2=uksum2+sum2;
            uksum=uksum+sum;
            br++;
            if(g==25){
                printf("2p %lf\t%lf\t%lf\t%lf\n",sum,sum2,uksum2,uksum);
            }
        }
        uksum2=uksum2/(br);
        uksum=uksum/(br);
        temp2=Nb/g;
        sigma[g-1]=sqrt((uksum2-(uksum*uksum))/(temp2-1));
        //printf("5 %d\n",g);
        printf("3 %lf\t%lf\t%lf\t%d\t%d\n",uksum2-(uksum*uksum),uksum,sigma[g-1],br,temp2);
    }
    fout=fopen("izlaz1.dat","w");
    for(i=0;i<200;i++){
        fprintf(fout,"%d\t%lf\n",i+1,sigma[i]);
    }
    fclose(fout);

    fclose(dat);

    return 0;

}
