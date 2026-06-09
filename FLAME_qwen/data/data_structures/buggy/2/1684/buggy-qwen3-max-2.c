#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The variable 'tmp' is declared but never used, and the initial 'getchar()' may consume a space or newline after the first number, causing misalignment in reading the next operator.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters unconditionally: the first as operator, the second as possibly a space or digit. However, if the input has no space (e.g., "5+3="), tmp will consume part of the next number, breaking scanf later. Also, if input ends with '=', this may read past it or cause undefined behavior.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [If 'tmp' already consumed part of the number (e.g., the first digit), this scanf will fail or read incorrectly. Additionally, the trailing space in "%d " may cause scanf to wait for non-whitespace after the number, which might not exist before '='.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}