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
            f(i,sum); // @@ [The function f is not returning the result of the recursive call, leading to undefined behavior when a recursive path exists. The return value is only set in the base case, but not propagated back up the recursion chain.]
            break;
        }
    }
    if(op==0) {
        return sum;
    }
} // @@ [Missing return statement when op==1; this leads to undefined behavior because the function does not return a value in all control paths.]
int main() {
    int i,sum1,max=0,op=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d %d",&x1[i],&m[i],&x2[i],&y2[i]);
    }
    for(i=0; i<n; i++) {
        sum1=f(i,1); // @@ [Because f has undefined behavior due to missing returns, sum1 may contain garbage values.]
        if(sum1>=max) {
            max=sum1;
            op=i;
        }
    }
    printf("%d\n",f(6,1)); // @@ [Hardcoded call to f(6,1) is invalid: index 6 may be out of bounds if n <= 6, and it serves no purpose per problem requirements. Also, f's undefined behavior affects this output.]

    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}