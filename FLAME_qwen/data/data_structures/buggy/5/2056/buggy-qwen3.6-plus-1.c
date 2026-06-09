#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct num{
    int coe;
    int exp;
};
int cmp(const void *e1,const void *e2){
    struct num *p1=(struct num*)e1;
    struct num *p2=(struct num*)e2;
    return -(p1->exp-p2->exp);
}
int main()
{   struct num in1[200],in2[200],out[500];
    int i,j,k;
    for(i=0;;i++){
        scanf("%d %d",&in1[i].coe,&in1[i].exp);
        if(in1[i].exp==0) // @@ Incorrect termination condition. The input ends with a newline, not necessarily a term with exponent 0. This may cause premature termination or reading errors.
        break;
    }
    int cnt1=i;
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0) // @@ Incorrect termination condition. The input ends with a newline, not necessarily a term with exponent 0. This may cause premature termination or reading errors.
        break;
    }
    int cnt2=j;
    for(i=0,k=0;i<=cnt1;i++){
        for(j=0;j<=cnt2;j++,k++){
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ Array out-of-bounds access when k equals cnt3-1. Also, the condition incorrectly excludes constant terms (exponent 0) from merging.
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp); // @@ Fails to check if the coefficient is zero before printing, which violates the requirement to only output non-zero terms.
    }
     return 0;
}