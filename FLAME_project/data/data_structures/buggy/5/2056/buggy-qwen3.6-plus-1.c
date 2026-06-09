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
        if(in1[i].exp==0) // @@ The loop termination condition assumes that the last term always has an exponent of 0. However, the problem states that only non-zero coefficient terms are input, and they are not guaranteed to end with exponent 0 (e.g., if the constant term is missing or if the input format doesn't strictly enforce ending with x^0 in a way that breaks the loop correctly for all cases, though typically polynomials have a constant term. More critically, this logic fails if the polynomial does NOT have a constant term (x^0), causing an infinite loop or reading into the next polynomial's data. But the bigger issue here is likely integer overflow or logic in multiplication/merging. Let's look closer. Actually, the prompt says "a_n n ... a_0 0". So the last term IS exponent 0. This part might be okay logically for parsing, but let's check the multiplication loop bounds.)
        break;
    }
    int cnt1=i;
    for(j=0;;j++){
        scanf("%d %d",&in2[j].coe,&in2[j].exp);
        if(in2[j].exp==0) // @@ Same as above, relies on presence of constant term.
        break;
    }
    int cnt2=j;
    for(i=0,k=0;i<=cnt1;i++){ // @@ Error: Loop should be i < cnt1. Using <= accesses in1[cnt1], which is out of bounds or contains uninitialized/garbage data because valid indices are 0 to cnt1-1.
        for(j=0;j<=cnt2;j++,k++){ // @@ Error: Loop should be j < cnt2. Using <= accesses in2[cnt2], which is out of bounds or contains uninitialized/garbage data.
            out[k].coe=in1[i].coe*in2[j].coe;
            out[k].exp=in1[i].exp+in2[j].exp;
        }
    }
    qsort(out,k,sizeof(out[0]),cmp);
    int cnt3=k;
    for(k=0;k<cnt3;k++){
        if(out[k].exp==out[k+1].exp && out[k+1].exp!=0){ // @@ Error: Accessing out[k+1] when k can be cnt3-1 leads to out-of-bounds access. Also, the merging logic is flawed; it modifies out[k+1] but prints out[k] immediately if not merged, skipping the accumulated result if it was merged into the next element incorrectly. The standard approach is to merge duplicates first, then print.
            out[k+1].coe+=out[k].coe;
            continue;
            }
        printf("%d %d ",out[k].coe,out[k].exp);
    }
     return 0;
}