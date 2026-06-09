#include<stdio.h>
int main(){
    int flag=1,x;
    scanf("%d",&x);
    int ans=0;
    int res=x;
    char ch=getchar(),tmp; // @@ [The initial `getchar()` reads the newline or space after the first number, but the following `ch=getchar(),tmp=getchar();` in the loop skips two characters per iteration, which may skip operators or digits. Also, `tmp` is unused and causes incorrect input parsing.]
    while(1){
        ch=getchar(),tmp=getchar(); // @@ [This reads two characters per loop iteration, which is incorrect. For example, if input is "5 - 1 * 2 =", after reading '5', the next characters are ' ', '-', ' ', '1', etc. This line will read '-' into `ch` and ' ' into `tmp`, which seems okay, but if there's no space (e.g., "5-1"), it reads '-' and '1', causing `ch` to be '-' and then `scanf("%d ",&x)` will fail because '1' is already consumed. Also, when encountering '=', this reads '=' and then tries to read another character (possibly undefined), and doesn't handle the end correctly.]
        if(ch=='='){
            ans+=flag*res;
            break;
        }
        scanf("%d ",&x); // @@ [`scanf` expects a number, but due to prior double `getchar()`, the digit might have already been consumed, leading to failed scan or wrong value. Also, trailing space in format may cause unexpected blocking or skipping.]
        if(ch=='*')res*=x;
        if(ch=='/')res/=x;
        if(ch=='+')ans+=flag*res,res=x,flag=1;
        if(ch=='-')ans+=flag*res,res=x,flag=-1;
    }printf("%d",ans);
}