#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); @@ The logic for reading input is flawed. It assumes a specific format (operator followed by space or number) and uses `getchar` and `scanf` in a way that skips characters or misinterprets spaces, especially with multiple consecutive divisions or multiplications. For example, after reading an operator into `ch`, it reads the next char into `tmp`. If the next token is a number, `tmp` might consume the first digit or a space, causing `scanf("%d ", &x)` to fail or read incorrectly. This approach does not robustly handle arbitrary spacing or sequences of operators like `/ /`.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); @@ This `scanf` expects an integer followed by a space. If the input has multiple spaces, no space, or ends with `=`, this can hang or read incorrectly. It also consumes the newline or space after the number, which might interfere with the next iteration's `getchar`.
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}