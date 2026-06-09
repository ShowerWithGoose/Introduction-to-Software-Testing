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
            f(i,sum); // @@ The return value of the recursive call is ignored, so the accumulated length from deeper recursion levels is lost. It should be `return f(i, sum);` or the result should be captured and returned.
            break;
        }
    }
    if(op==0) {
        return sum;
    }
    // @@ Missing return statement for the case where op==1 (a connection was found). This leads to undefined behavior as the function does not return a value in this path.
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
    printf("%d\n",f(6,1)); // @@ This line prints an incorrect debug value (calling f with index 6 which may be out of bounds or irrelevant) and adds an extra newline, causing the output format to mismatch the expected output.
    
    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}