#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; @@ [Using uninitialized variable 'tmp' and incorrect input parsing logic; also, the comma operator in 'ch=getchar(),tmp=getchar();' reads two characters but only uses 'ch', potentially skipping operators or digits]
    while(1){
        ch=getchar(),tmp=getchar(); @@ [Same issue: reads two characters per loop iteration, which may consume part of the next number or operator incorrectly; also 'tmp' is unused]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); @@ [After reading two characters above, this scanf may not align with the actual input stream, causing misreads or infinite loops]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}