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
    }num=0; // @@ [This resets 'num' to 0 after storing coefficients, so when storing exponents next, it overwrites the same 'ans' entries instead of continuing from where coefficients left off. This breaks the parallel structure between coefficient and exponent storage.]
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
        sum(i+1); // @@ [Recursive call may cause stack overflow for large inputs, but more critically, this function does not handle merging all consecutive like terms correctly in a single pass and is used improperly in main. Also, it doesn't return a value in all paths (missing return after recursive call), leading to undefined behavior.]
    }
}
int main() {
    int i=0,j=0;
    scanf("%d",&x1[0]);
    while(getchar()!='\n'){ // @@ [This loop reads one integer per iteration but increments index before reading, which may skip or misalign input parsing. Also, it assumes alternating coeff/exponent without validating count parity, and fails on empty lines or trailing spaces.]
        scanf("%d",&x1[++i]);
    }scanf("%d",&x2[0]);
    while(getchar()!='\n'){ // @@ [Same issue as above: incorrect input parsing logic that doesn't properly pair coefficients and exponents, especially when number of terms is odd or input ends unexpectedly.]
        scanf("%d",&x2[++j]);
    }
    multi(i,j); // @@ ['i' and 'j' are last indices, not counts. For example, if input has 4 numbers (2 terms), i=3, but loop in multi uses k < i (k<3), which with k+=2 gives k=0,2 → correct count? But then second loop uses k < i+1 → k<4 → k=1,3 → also correct? However, combined with the reset of 'num', the real issue is decoupling coeff and exponent storage.]
    qsort(ans,num,sizeof(anew),cmp);
    for (int k = 0; k <num; ++k) {
        if(ans[k].n==ans[k+1].n){ // @@ [Accesses ans[k+1] when k == num-1 → out-of-bounds read, causing undefined behavior (likely crash).]
            k=sum(k); // @@ [sum() modifies ans in-place but returns an index; however, the logic assumes that after merging, only ans[k] is valid, but sum() merges into ans[k+1], so printing ans[k] prints the zeroed/old term. Also, recursive sum doesn't handle multiple merges properly.]
            printf("%lld %lld ",ans[k].an,ans[k].n);
        }else
        printf("%lld %lld ",ans[k].an,ans[k].n);
    }
    return 0;
}