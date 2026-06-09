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
            printf("%c",ch1); // @@ 不必要的输出，导致输出包含表达式而非只输出结果。
            if(ch1!=' '){
                a=ch1-'0'; // @@ 当ch1为负号时，错误地将负号当作数字处理，无法正确处理以负号开头的表达式。
                break;
            }
        }
        while(1){
            scanf("%c",&ch2);
            printf("%c",ch2); // @@ 不必要的输出。
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
    printf("%d",sum);
    return 0;
}