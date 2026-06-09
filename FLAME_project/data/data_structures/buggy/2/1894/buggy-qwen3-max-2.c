#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a); // @@ [Using "%lld %c" skips whitespace before %c, but the input may have no space before '=' or operators; also, this format fails to correctly parse numbers followed directly by operators without space. Additionally, when reading after '*' or '/', it uses "%d" instead of "%lld", causing type mismatch and incorrect reads.]
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); // @@ [Should use "%lld" to match the type of 'num' (long long). Using "%d" leads to undefined behavior and wrong values being read.]
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); // @@ [This reads only one character, but may leave newline or space in buffer; more critically, it doesn't skip whitespace, so it might read a space as the next operator, breaking logic. Also, after reading the last number before '=', this may not handle the '=' correctly due to spacing issues.]
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