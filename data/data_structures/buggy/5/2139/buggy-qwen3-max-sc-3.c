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
    }num=0; // @@ [This resets 'num' to 0 after filling the coefficients, causing loss of coefficient data before exponents are assigned. The exponent loop then overwrites the same 'ans' entries starting from index 0, breaking the pairing between coefficients and exponents.]
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
        sum(i+1); // @@ [Recursive call may cause stack overflow for large inputs, and more critically, this function does not handle cases where ans[i+1] is beyond array bounds (e.g., when i is the last index). Also, it returns nothing in the 'else' branch, leading to undefined behavior.]
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
    multi(i,j); // @@ [The parameters passed are the last indices (counts minus one), but the logic in 'multi' assumes 'i' and 'j' represent total number of elements or upper bounds incorrectly. Specifically, input reading stores 2*N values in x1[0..i], so i+1 is the count, but the loops in 'multi' use 'i' and 'j' as exclusive upper bounds with step 2, which may skip or overrun terms.]
    qsort(ans,num,sizeof(anew),cmp);
    for (int k = 0; k <num; ++k) {
        if(ans[k].n==ans[k+1].n){ // @@ [Accesses ans[k+1] when k == num-1, leading to out-of-bounds read (undefined behavior).]
            k=sum(k); // @@ [The function 'sum' has undefined behavior (no return in else branch) and modifies data in a way that doesn't correctly merge like terms across the entire array. Also, after merging, it prints only ans[k], but the merged result is stored in ans[k+1], so wrong term is printed.]
            printf("%lld %lld ",ans[k].an,ans[k].n);
        }else
        printf("%lld %lld ",ans[k].an,ans[k].n);
    }
    return 0;
}