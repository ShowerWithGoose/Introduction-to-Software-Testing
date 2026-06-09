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
            scanf("%d",&num); // @@ This should be "%lld" because num is long long. Using "%d" causes undefined behavior for large numbers and mismatch with variable type.
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ This should be " %c" to skip whitespace before reading the operator. Without the leading space, it will read a whitespace character (e.g., space) instead of the next operator, causing incorrect parsing and early termination.
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