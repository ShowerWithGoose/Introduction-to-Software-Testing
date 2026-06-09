#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ This line reads a character (likely a space) left after scanf, not the expected operator. This causes misalignment in parsing and should be removed or handled properly.
    while(1){
        ch=getchar(),tmp=getchar(); // @@ This reads two characters unconditionally. The second character (tmp) is never used and may consume a digit or space that belongs to the next number, leading to incorrect integer parsing.
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