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
            printf("%c",ch1); // @@ [Unnecessary output that corrupts the result; problem requires only final integer output]
            if(ch1!=' '){
                a=ch1-'0';
                break;
            }
        }
        while(1){
            scanf("%c",&ch2);
            printf("%c",ch2); // @@ [Unnecessary output that corrupts the result; problem requires only final integer output]
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
            sum+=b; // @@ [Incorrect accumulation logic: when encountering '-', it should subtract, but current logic adds negative b only after setting b=-1 for next term, which is too late for current term]
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
    printf("%d",sum); // @@ [Logic error in handling subtraction: the current term's sign is not correctly applied because b=-1 is set for the next term, not the current one]
    return 0;
}