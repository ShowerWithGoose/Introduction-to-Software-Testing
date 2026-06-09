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
            f(i,sum); // @@ The return value of the recursive call is not used, so the accumulated sum is lost; should be: sum = f(i, sum);
            break;
        }
    }
    if(op==0) {
        return sum;
    }
    // @@ Missing return statement for the case when op==1 (a match is found but the loop breaks); the function may return an undefined value.
}
int main() {
    int i,sum1,max=0,op=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d %d",&x1[i],&m[i],&x2[i],&y2[i]);
    }
    for(i=0; i<n; i++) {
        sum1=f(i,1);
        if(sum1>=max) {
            max=sum1;
            op=i;
        }
    }
    printf("%d\n",f(6,1)); // @@ Hardcoded index 6 is incorrect; should use a valid index or remove this debugging line.
    
    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}