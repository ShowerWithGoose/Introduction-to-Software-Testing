#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters at once, which skips every other operator or symbol. For example, in "24 / 4 / 3 / 2 + ...", it reads '/' then ' ', and next iteration reads '/' then ' ', missing the '+' later. This causes incorrect parsing of operators and operands.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [The space after %d consumes trailing whitespace, but due to the double getchar() above, the input stream is already misaligned, causing scanf to read wrong numbers or fail to parse correctly.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}