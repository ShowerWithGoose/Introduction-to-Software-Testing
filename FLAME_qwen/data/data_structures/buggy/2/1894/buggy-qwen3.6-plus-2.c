#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a);
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ Format specifier '%d' is for 'int', but 'num' is declared as 'long long'. This type mismatch can cause compilation errors (especially with strict warning flags) or undefined behavior. It should be '%lld'.
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ '%c' does not skip leading whitespace, so it will incorrectly read the space after the number instead of the next operator. It should be 'scanf(" %c",&a);' to properly skip whitespace.
        }
        result+=tmp;
        if(a=='+'){
            tmp=1;
        }else if(a=='-'){
            tmp=-1;
        }else{
            printf("%lld",result);
            break;
        }
    }
return 0;
}