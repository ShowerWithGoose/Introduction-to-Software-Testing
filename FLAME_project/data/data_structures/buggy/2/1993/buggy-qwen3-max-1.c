#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char ch1,ch2;
    int sum=0,a,b=1,flat=1;
    while(1){
        while(1){
            scanf("%c",&ch1);
            printf("%c",ch1); // @@ [Unnecessary output; problem requires only final result, not echoing input. Also interferes with judging.]
            if(ch1!=' '){
                a=ch1-'0';
                break;
            }
        }
        while(1){
            scanf("%c",&ch2);
            printf("%c",ch2); // @@ [Same issue: printing input characters causes wrong output format and extra characters before result.]
            if(ch2>='0'&&ch2<='9'){
                a*=10;a+=ch2-'0';
            }
            if(ch2=='+'||ch2=='-'||ch2=='*'||ch2=='/'||ch2=='='){
                break;
            }
        }
        if(ch2=='+'||ch2=='-'||ch2=='='){
            if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
            flat=1;
            sum+=b;
            b=1;
            if(ch2=='-'){
                b=-1;
            }
        }else if(ch2=='*'||ch2=='/'){
            if(ch2=='*'){
                if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
                flat=1;
            }else if(ch2=='/'){
                if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
                flat=2;
            }
        }
        if(ch2=='='){
            break;
        }
    }
    printf("\n");
    printf("%d",sum); // @@ [Logic error: does not correctly handle operator precedence and accumulation for subtraction. Specifically, when encountering '-', it sets b = -1 but doesn't apply the current 'a' properly in context of multiplication/division chain. Also, initial handling of first number is flawed because it assumes b starts at 1 and multiplies, which fails for expressions starting with subtraction or when flat state is inconsistent.]
    return 0;
}