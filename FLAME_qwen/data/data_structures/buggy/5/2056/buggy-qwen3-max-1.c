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
        if(in1[i].exp==0)
        break;
    }
    int cnt1=i; @@ [The loop breaks when exponent is 0, but a term with exponent 0 may not be the last term; input may have multiple terms including constant term not at end, or polynomial may not contain a constant term at all. This causes premature termination of input reading.]
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j; @@ [Same issue as above: assumes exponent 0 marks end of input, which is incorrect per problem statement. Input ends with newline, not necessarily with exponent 0.]
    for(i=0,k=0;i<=cnt1;i++){ @@ [Loop condition should be i < cnt1, not i <= cnt1. Since cnt1 = i after break, valid indices are 0 to cnt1-1. Using <= accesses in1[cnt1], which is uninitialized.]
        for(j=0;j<=cnt2;j++,k++){ @@ [Same error: should be j < cnt2, not j <= cnt2. Accesses in2[cnt2], which is beyond valid input.]
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ @@ [Accesses out[k+1] when k == cnt3-1, leading to out-of-bounds read. Also, merging logic is flawed: it only merges consecutive duplicates and skips printing merged terms correctly.]
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}