#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0; // @@ Declaration after statement (C89 compilers require declarations at block start)
    int res=x; // @@ Declaration after statement
    char ch=getchar(),tmp; // @@ Declaration after statement
    while(1){
        ch=getchar(),tmp=getchar();
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