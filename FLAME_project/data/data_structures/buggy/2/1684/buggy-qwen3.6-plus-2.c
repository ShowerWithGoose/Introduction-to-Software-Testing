#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp;
    while(1){
        ch=getchar(),tmp=getchar(); // @@ The logic for reading input is flawed. It assumes a specific format (operator followed by space or number) but fails to handle spaces correctly before the operator or number, and `tmp` consumes the next character which might be part of the number or an operator, leading to misalignment. Specifically, after reading the initial number, `getchar()` reads the space. Then inside the loop, `ch=getchar()` reads the operator, but `tmp=getchar()` reads the next character. If the next character is a space, `scanf("%d ", &x)` might work, but if it's a digit, `tmp` has consumed the first digit of the next number, causing `scanf` to read the remaining digits incorrectly or fail. For example, in "24 / 4", after reading 24, `ch` becomes ' ', `tmp` becomes '/'. Then `scanf` tries to read an integer from " 4...", which works. But in complex cases with multiple spaces or immediate operators/numbers, this breaks. More critically, the logic `if(ch=='*')res*=x;` etc. relies on `ch` being the operator. However, the input parsing `ch=getchar(), tmp=getchar()` skips characters unpredictably relative to the `scanf`. A robust parser needs to skip whitespace explicitly before reading operators and numbers.
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ This scanf expects an integer followed by a space. If the next token is not immediately parseable as an integer due to previous consumption by `tmp`, or if the format doesn't match exactly (e.g., no trailing space before newline or =), it fails. Also, `tmp` in the previous line likely consumed the first digit of `x` if there was no space between operator and number, or consumed a space if there was one, making this scanf unreliable.
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}