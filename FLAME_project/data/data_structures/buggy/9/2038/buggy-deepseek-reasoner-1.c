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
            f(i,sum); // @@ Recursive call return value is ignored; should be assigned or returned to propagate the chain length.
            break;
        }
    }
    if(op==0) {
        return sum;
    }
} // @@ Function lacks a return statement when op=1 (i.e., when a match is found), causing undefined behavior.
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
    printf("%d\n",f(6,1)); // @@ Debug line that prints an incorrect value and produces extraneous output; should be removed.
    
    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}