#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    long long result=0,tmp=1,num;
    char a;
    while(1){
        scanf("%lld %c",&num,&a); @@ [Mismatch between format specifier and variable type in subsequent scanf calls; also, initial tmp=1 logic fails for subtraction]
        tmp*=num;
        while(a=='*'||a=='/'){
            scanf("%d",&num); @@ [Using %d to read into long long variable 'num' causes undefined behavior; should be %lld]
            if(a=='*'){
                tmp*=num;
            }else{
                tmp/=num;
            }
            scanf("%c",&a); @@ [Does not skip whitespace; may read newline or space as operator, causing incorrect parsing]
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