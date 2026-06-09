#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [The program reads two characters at once, which skips necessary input and causes misalignment in parsing operators and numbers. It should read only one character (the operator) per iteration.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [Because of the double getchar() above, the operator is incorrectly read, so this scanf may not align with the actual next number in input, leading to incorrect parsing or runtime issues.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}