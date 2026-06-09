#include <stdio.h>
int x1[1000];
int x2[1000];
int m[1000];
int y2[1000];
int n;
int f(int j,int sum) {
    int i,op=0;
    for(i=0; i<n; i++) {
        if((x2[j]==x1[i])&&(y2[j]==m[i])) {
            op=1;
            sum++;
            f(i,sum); // @@ [The function f is supposed to return the chain length, but the recursive call's return value is ignored. This leads to incorrect accumulation of 'sum'. Also, the function does not always return a value (missing return in recursive path).]
            break;
        }
    }
    if(op==0) {
        return sum;
    }
} // @@ [Missing return statement when op==1; function may fall off without returning a value, causing undefined behavior.]

int main() {
    int i,sum1,max=0,op=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d %d",&x1[i],&m[i],&x2[i],&y2[i]);
    }
    for(i=0; i<n; i++) {
        sum1=f(i,1); // @@ [Because f has undefined behavior due to missing return, sum1 may get garbage values.]
        if(sum1>=max) {
            max=sum1;
            op=i;
        }
    }
    printf("%d\n",f(6,1)); // @@ [Hardcoded call f(6,1) is invalid: index 6 may be out of bounds if n <= 6, and it serves no purpose per problem requirements. Also, f's undefined behavior affects this.]

    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}