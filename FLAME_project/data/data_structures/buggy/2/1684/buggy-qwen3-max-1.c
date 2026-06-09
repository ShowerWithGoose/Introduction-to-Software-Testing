#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters at once, which skips every other operator or symbol. For example, in "24 / 4 / 3...", after reading '24', the first getchar() gets space, second gets '/', but then next loop reads space and next '/', skipping operands and breaking parsing.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [This assumes that after an operator there's always a number followed by a space, but the input may not have a trailing space before '=' or end of token, leading to incorrect parsing or missed tokens. Also, due to double getchar above, the operator is often misaligned with the operand read here.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}