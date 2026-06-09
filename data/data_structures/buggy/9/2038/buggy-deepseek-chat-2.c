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
            f(i,sum); // @@ The return value of the recursive call is not used, so the accumulated sum is lost; the function should return the result of the recursive call.
            break;
        }
    }
    if(op==0) {
        return sum;
    }
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
    printf("%d\n",f(6,1)); // @@ This line uses a hardcoded index 6, which may be out of bounds and is not part of the required output format.
    
    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}