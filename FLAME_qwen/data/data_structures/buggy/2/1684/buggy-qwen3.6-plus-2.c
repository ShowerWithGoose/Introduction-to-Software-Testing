#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ Reads a character after the first number but does not reliably skip whitespace, leading to misalignment in subsequent parsing.
    while(1){
        ch=getchar(),tmp=getchar(); // @@ getchar() does not skip whitespace and consumes two characters, which will incorrectly read digits of the next number if spaces are missing. Should use scanf(" %c", &ch) to skip whitespace and read the operator.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ The trailing space in the format string causes scanf to wait for a non-whitespace character after reading the integer, potentially causing the program to hang or misalign input parsing.
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}