#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a); // @@ [This reads a number and a character, but skips whitespace. However, the input may have multiple spaces or no space before '=', causing misreads. Also, using "%lld %c" consumes one space but leaves other whitespace (like newline or multiple spaces) which can break parsing.]
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ [Using %d here instead of %lld causes type mismatch: 'num' is long long, but %d reads into int. This leads to undefined behavior and incorrect values. Should be %lld.]
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ [This reads only one character without skipping whitespace. If there are spaces after operator, 'a' becomes space, breaking the loop prematurely and misparsing the next token.]
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