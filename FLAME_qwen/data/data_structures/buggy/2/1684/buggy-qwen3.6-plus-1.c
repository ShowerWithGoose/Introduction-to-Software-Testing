#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ Reads the character immediately after the first number, which is typically a space, causing the subsequent loop to misalign with the actual operators.
    while(1){
        ch=getchar(),tmp=getchar(); // @@ Consumes exactly two characters per iteration regardless of spacing, which breaks parsing when there are multiple spaces, no spaces, or when the operator is not in the expected position. Should use scanf(" %c", &ch) to skip whitespace.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ The trailing space in the format string forces scanf to skip whitespace after the number, which can cause the program to hang waiting for additional non-whitespace input. Remove the trailing space.
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}