#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The variable 'tmp' is declared but never used, and the logic for reading input is flawed. The line reads two characters immediately after the first number, which may consume part of the next token or whitespace incorrectly.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters unconditionally in every loop iteration, which skips necessary input tokens (like digits or operators) and causes misalignment in parsing the expression. It also fails to handle spaces properly as per the problem's input format.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [This assumes that after reading two characters, the next token is an integer. However, due to incorrect character consumption above, this may read from a misaligned position, leading to undefined behavior or wrong values. Also, trailing space in format string may cause unexpected blocking on input.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}