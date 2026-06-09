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
    int cnt1=i;
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0)
        break;
    }
    int cnt2=j;
    for(i=0,k=0;i<=cnt1;i++){ // @@ The loop condition should be i < cnt1, not i <= cnt1, because cnt1 is the index of the last term (exponent 0), and the loop should include that term but not go beyond the array bounds. However, the input reading logic is flawed: the loop breaks when exponent is 0, so the term with exponent 0 is stored at index i, but then cnt1 = i, which is the index of that term. Using i <= cnt1 includes an extra iteration with uninitialized data.
        for(j=0;j<=cnt2;j++,k++){ // @@ Same issue: loop condition should be j < cnt2, not j <= cnt2, for the same reason as above.
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){ // @@ The loop variable k is reused, overwriting the previous value of k (cnt3). This causes the loop to use k as both the index and the count, leading to incorrect behavior.
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ This condition accesses out[k+1] when k = cnt3-1, which is out of bounds. Also, the condition out[k+1].exp!=0 is incorrect because terms with exponent 0 should also be combined if they have the same exponent.
            out[k+1].coe+=out[k].coe;
            continue; // @@ The continue statement skips the printf for the current term, but the combined term is printed later. However, this logic fails to handle multiple consecutive same exponents correctly and may skip printing terms that should be printed.
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}