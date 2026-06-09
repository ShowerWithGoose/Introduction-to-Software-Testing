#include <stdio.h>
#include <stdlib.h>
int x1[100]={0},x2[100]={0},num=0;
typedef struct x{
    long long an;
    long long n;
}anew;
anew ans[200];
void multi(int i,int j){
    for (int k = 0; k < i; k+=2) {
        for (int l = 0; l < j; l+=2) {
             ans[num++].an=x1[k]*x2[l];
        }
    }num=0; // @@ [This resets 'num' to 0 after storing coefficients, causing loss of coefficient data before exponents are assigned. The exponent loop then overwrites the same 'ans' entries starting from index 0, breaking the pairing between coefficients and exponents.]
    for (int k = 1; k < i+1; k+=2) {
        for (int l = 1; l < j+1; l+=2) {
            ans[num++].n=x1[k]+x2[l];
        }
    }
}
int cmp(const void *e1,const void *e2){
    long long i=((((anew*)e2)->n)-(((anew*)e1)->n));
    if(i>0) return 1;
    else if(i<0) return -1;
    else return 0;
}
int sum(int i){
    if(ans[i].n!=ans[i+1].n){
        return i;
    }else{
        ans[i+1].an+=ans[i].an;
        sum(i+1); // @@ [Recursive call may access out-of-bounds memory when i+1 >= num. Also, this function does not handle cases where multiple consecutive terms have the same exponent correctly, and it doesn't update 'num' or remove merged terms.]
    }
}
int main() {
    int i=0,j=0;
    scanf("%d",&x1[0]);
    while(getchar()!='\n'){
        scanf("%d",&x1[++i]);
    }scanf("%d",&x2[0]);
    while(getchar()!='\n'){
        scanf("%d",&x2[++j]);
    }
    multi(i,j); // @@ [The parameters passed are the last indices (i and j), but the logic in multi assumes they represent counts or bounds. Since input reads alternating coeff/exponent pairs into x1[0], x1[1], ..., the total number of elements is i+1 and j+1, but the loops in multi use i and j as upper bounds incorrectly.]
    qsort(ans,num,sizeof(anew),cmp);
    for (int k = 0; k <num; ++k) {
        if(ans[k].n==ans[k+1].n){ // @@ [Accesses ans[k+1] when k == num-1, leading to out-of-bounds read.]
            k=sum(k); // @@ [The sum function modifies terms but returns an index that may skip terms or cause incorrect iteration. Also, after merging, the next term (k+1) might still need merging with further terms, which this logic doesn't handle properly.]
            printf("%lld %lld ",ans[k].an,ans[k].n);
        }else
        printf("%lld %lld ",ans[k].an,ans[k].n);
    }
    return 0;
}