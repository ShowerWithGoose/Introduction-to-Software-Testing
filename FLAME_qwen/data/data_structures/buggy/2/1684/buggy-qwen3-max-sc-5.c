#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The variable 'tmp' is declared but never used, and the logic for reading input is flawed. The line 'ch=getchar(),tmp=getchar();' consumes two characters at once, which may skip operators or digits, especially since after reading the first integer with scanf, the next character (often a space or operator) is read into 'ch', and the following one (possibly the operator or a space) into 'tmp', leading to incorrect parsing.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters per loop iteration, which disrupts the expected input format. For example, in "5 - 1 * 2 =", after reading 5, the first getchar() might get ' ' and the second '-', then next loop gets ' ', then '1' — but '1' is not an operator, causing logic failure. Also, when '=' is encountered, it may not be read correctly due to double consumption.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [This assumes that after reading two characters, the next token is an integer. However, due to incorrect character consumption above, the file pointer may be misaligned, causing scanf to fail or read wrong values. Additionally, the trailing space in "%d " can cause unexpected blocking or skipping.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}