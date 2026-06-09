#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a); // @@ [Mismatch between format specifier and variable type in subsequent scanf calls: using %d for long long 'num' later causes undefined behavior]
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ [Using %d to read into 'num' which is of type long long; should use %lld]
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ [This reads any character including whitespace; may read space instead of operator due to unhandled whitespace in input]
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