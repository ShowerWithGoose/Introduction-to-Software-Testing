#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a); // @@ [Using %lld for long long but later using %d for the same variable 'num' causes type mismatch and undefined behavior]
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ [Mismatched format specifier: %d is used for int, but 'num' is long long; should be %lld]
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ [This reads any character including whitespace; may read newline or space instead of next operator, causing logic errors]
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