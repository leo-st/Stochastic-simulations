#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *dat,*fout;
    char tekst[500];
    float temp,sum,sum2,uksum,uksum2;
    int temp1,temp2;
    float E[1000], sigma[200];
    int i,g,j,k,br;
    int Nb=1000;

    dat = fopen("test_E.dat","r");
    fgets(tekst,500,(FILE*)dat);
    fgets(tekst,500,(FILE*)dat);

    for(i=0;i<1000;i++){
        fscanf(dat, " %d %f %f %f %d ",&temp1,&E[i],&temp,&temp,&temp1);
        printf("%d\t%f\n",i,E[i]);
    }
    for(g=1;g<=Nb/5;g++){
        uksum2=0.0;
        uksum=0.0;
        br=0;
        for(j=0;j<Nb;j=j+g){
                if(j+g>Nb){
                    break;
                }
                sum=0;
            for(k=j;k<j+g;k++){

                sum=sum+E[k];
                if(g==37 && k>960){
                    printf("\n%d\t%d\t%f\n",j,k,E[k]);
                }
            }
            sum=sum/g;
            sum2=sum*sum;
            uksum2=uksum2+sum2;
            uksum=uksum+sum;
            br++;
            if(g==37){
                printf("%f\t%f\t%f\t%f\n",sum,sum2,uksum2,uksum);
            }
        }
        uksum2=uksum2/(br);
        uksum=uksum/(br);
        temp2=Nb/g;
        sigma[g-1]=sqrt((uksum2-(uksum*uksum))/(temp2-1));
        printf("%f\t%f\t%f\n",uksum2,uksum,sigma[g-1]);
    }
    fout=fopen("izlaz.dat","w");
    for(i=0;i<200;i++){
        fprintf(fout,"%d\t%f\n",i+1,sigma[i]);
    }
    fclose(fout);

    fclose(dat);

    return 0;

}
