#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The initial `getchar()` reads the newline or space after the first number, but then inside the loop, two `getchar()` calls consume two characters per iteration, which may skip operators or digits. Also, `tmp` is unused and this approach misaligns input parsing.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters each loop iteration, which can skip over parts of the input (e.g., if there's only one space before a number, it might consume the operator and part of the number). This causes incorrect parsing of operators and operands.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [`scanf` with trailing space consumes whitespace, but due to prior double `getchar()`, the input stream may be misaligned, causing `scanf` to fail or read incorrectly. Also, if the expression ends without space before '=', this may block or misread.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}