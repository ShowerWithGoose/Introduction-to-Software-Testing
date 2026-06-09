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
            f(i,sum); // @@ [The recursive call's return value is ignored, so the accumulated sum from deeper recursion is lost. This causes the function to return an incorrect (usually smaller) count.]
            break;
        }
    }
    if(op==0) {
        return sum;
    }
    // @@ [Missing explicit return statement when op == 1. In this case, the function reaches the end without returning a value, leading to undefined behavior.]
}
int main() {
    int i,sum1,max=0,op=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d %d",&x1[i],&m[i],&x2[i],&y2[i]);
    }
    for(i=0; i<n; i++) {
        sum1=f(i,1); // @@ [Because f() has undefined behavior when a chain continues (no return after recursive call), sum1 may get garbage values.]
        if(sum1>=max) {
            max=sum1;
            op=i;
        }
    }
    printf("%d\n",f(6,1)); // @@ [This line prints an arbitrary debug output (f(6,1)) which is not part of the required output format and will cause wrong answer. Also, index 6 may be out of bounds for small n like 2.]

    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}