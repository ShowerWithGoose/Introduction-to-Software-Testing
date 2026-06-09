#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); // @@ This line reads two characters, but the input format may have spaces or the second character may not be needed. The `tmp` variable is never used, and this read may consume the operator or space incorrectly.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ The space in the format string may cause issues with input parsing, especially when reading after a character. It may skip too many characters or cause unexpected behavior.
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}