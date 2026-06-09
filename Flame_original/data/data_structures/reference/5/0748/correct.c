#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct polynomial
{
    int coefficient;
    int exponential;
};
typedef struct polynomial strp;

int main()
{
    int i=0,j=0,k=0,p=0,q=0,m=0,n=0,temp1=0,temp2=0;
    strp num1[500];
    strp num2[500];
    char flag;
    int coe[500],exp[500];
    do
    {
        scanf("%d%d%c",&num1[i].coefficient,&num1[i].exponential,&flag);
        i++;
    }
    while(flag!='\n');
    do
    {
        scanf("%d%d%c",&num2[j].coefficient,&num2[j].exponential,&flag);
        j++;
    }
    while(flag!='\n');
    for(k=0;k<i;k++){
        for(p=0;p<j;p++){
            coe[q]=num1[k].coefficient*num2[p].coefficient;
            exp[q]=num1[k].exponential+num2[p].exponential;
            q++;
        }
    }
    for(i=0;i<q;i++){
        for(j=i+1;j<q;j++){
            if(exp[i]<exp[j]){
                temp1=exp[i];
                exp[i]=exp[j];
                exp[j]=temp1;
                temp2=coe[i];
                coe[i]=coe[j];
                coe[j]=temp2;
            }
            else
                continue;
        }
    }
    for(i=0;i<q;i++){
        if(exp[i]==exp[i+1]&&exp[i]!=0){
            coe[i+1]=coe[i]+coe[i+1];
            coe[i]=0;
        }
        else
            continue;
    }
    for(n=0;n<q;n++){
        if(coe[n]!=0){
            printf("%d %d ",coe[n],exp[n]);
        }
        else
            continue;
    }
    return 0;
}





