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
        if(in1[i].exp==0) // @@ The input termination condition is incorrect. The problem states that input ends with a newline, not when exponent is 0. This will incorrectly stop reading if a term has exponent 0 but is not the last term, or fail to read all terms if the last exponent is not 0.
        break;
    }
    int cnt1=i;
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0) // @@ Same issue as above; termination condition is wrong.
        break;
    }
    int cnt2=j;
    for(i=0,k=0;i<=cnt1;i++){ // @@ Loop condition should be i < cnt1 (not <=), because cnt1 is the index of the last read term, and the loop should iterate over all terms from 0 to cnt1-1. Using <= causes out-of-bounds access.
        for(j=0;j<=cnt2;j++,k++){ // @@ Same issue: should be j < cnt2, not <=.
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){ // @@ The loop variable k is reused, overwriting the previous value of k (the number of terms). This causes incorrect iteration bounds.
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ Accessing out[k+1] when k = cnt3-1 leads to out-of-bounds access. Also, the condition out[k+1].exp!=0 is incorrect; terms with exponent 0 should still be combined if they have the same exponent.
            out[k+1].coe+=out[k].coe;
            continue; // @@ Using continue skips the printf for the current term, but the logic is flawed: it should combine coefficients and then skip the next term, not skip printing the current one. This results in missing output for combined terms.
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}