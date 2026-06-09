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
            f(i,sum); // @@ [The function f is not returning the result of the recursive call, leading to undefined behavior when trying to use its return value. This causes logical errors in computing the chain length.]
            break;
        }
    }
    if(op==0) {
        return sum;
    }
} // @@ [Missing return statement when op==1; control reaches end of non-void function, which is undefined behavior and likely causes incorrect results or crashes.]
int main() {
    int i,sum1,max=0,op=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d %d",&x1[i],&m[i],&x2[i],&y2[i]);
    }
    for(i=0; i<n; i++) {
        sum1=f(i,1); // @@ [Because f has undefined behavior due to missing return in some paths, sum1 may get garbage values, leading to incorrect max calculation.]
        if(sum1>=max) {
            max=sum1;
            op=i;
        }
    }
    printf("%d\n",f(6,1)); // @@ [Hardcoded call to f(6,1) is invalid if n <= 6; also, f has undefined behavior, so this print is erroneous and unnecessary per problem spec.]
    
    printf("%d %d %d",max,x1[op],m[op]);
    return 0;
}