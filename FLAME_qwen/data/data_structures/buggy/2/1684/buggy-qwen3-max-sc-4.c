#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The initial `getchar()` reads the newline or space after the first number, but then inside the loop, two `getchar()` calls consume two characters per iteration, which may skip operators or digits. This causes incorrect parsing of the input expression.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This line consumes two characters per loop iteration. If the input has single-character tokens (like ' + ', with spaces), this may read past the operator into the next number or whitespace, leading to misinterpretation of the operator or missing it entirely. Also, `tmp` is never used, indicating flawed logic.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [If the previous `getchar()` calls have already consumed part of the next number or whitespace incorrectly, this `scanf` may fail or read wrong values. Additionally, the format string "%d " skips trailing whitespace, but combined with prior character reads, it leads to inconsistent input parsing.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}