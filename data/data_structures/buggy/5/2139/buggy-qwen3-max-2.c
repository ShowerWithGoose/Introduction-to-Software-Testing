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
    }num=0; // @@ [This resets 'num' to 0 after storing coefficients, causing loss of coefficient data before exponents are assigned. Exponents will overwrite the same 'ans' entries starting from index 0, breaking the pairing between coefficients and exponents.]
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
        sum(i+1); // @@ [Recursive call may access out-of-bounds memory when i+1 >= num. Also, function returns int but recursive path doesn't return a value, leading to undefined behavior.]
    }
}
int main() {
    int i=0,j=0;
    scanf("%d",&x1[0]);
    while(getchar()!='\n'){ // @@ [This loop assumes every non-newline character is followed by a valid integer input, but it consumes one character per iteration without checking if more integers exist. It may fail to read all inputs correctly or cause undefined behavior if input format isn't perfectly matched.]
        scanf("%d",&x1[++i]);
    }scanf("%d",&x2[0]);
    while(getchar()!='\n'){ // @@ [Same issue as above: incorrect input parsing logic that may miss inputs or read invalid data.]
        scanf("%d",&x2[++j]);
    }
    multi(i,j); // @@ ['i' and 'j' represent last index, not count. The function expects counts but receives indices, leading to off-by-one errors in loops.]
    qsort(ans,num,sizeof(anew),cmp);
    for (int k = 0; k <num; ++k) {
        if(ans[k].n==ans[k+1].n){ // @@ [Accesses ans[k+1] when k == num-1, which is out-of-bounds.]
            k=sum(k); // @@ [sum() has undefined behavior (no return in else branch) and may return uninitialized/garbage value, leading to unpredictable loop behavior.]
            printf("%lld %lld ",ans[k].an,ans[k].n);
        }else
        printf("%lld %lld ",ans[k].an,ans[k].n);
    }
    return 0;
}