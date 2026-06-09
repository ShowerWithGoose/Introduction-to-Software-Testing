#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ This line consumes one character from input, which may be part of the operator or the '=', causing incorrect parsing. It assumes a space or character after the first integer, but such a character may not exist or may be the operator itself.
    while(1){
        ch=getchar(),tmp=getchar(); // @@ This line reads two characters at once, assuming the input format is operator followed by a space or character. However, the expression may have no spaces or varying spacing, causing misreading of operators and numbers. For example, if there are no spaces, this reads the next digit as the operator and the following character as 'tmp', leading to incorrect parsing.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x);
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}