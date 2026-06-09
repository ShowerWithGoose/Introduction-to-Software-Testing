#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a1,a2,a3;
    a1=0;
    char b1,b2,b3;
    b1='+';
    if(b1!='='){  // @@ Should be 'while' instead of 'if' to loop through the entire expression.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3);  // @@ Missing '&' before b3: should be &b3.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){  // @@ Condition a3!='0' compares integer to character literal; should be a3!=0 (or simply remove the check as input is valid).
                a2/=a3;
            }
            b2=b3;    
        }
        else if(b2=='+' || b2=='-'){
        if(b1=='+'){
            a1+=a2;
        }
        else if(b1=='-'){
            a1-=a2;
        }
            b1=b2;
        }
        }
        else if(b1=='=')
        {
            printf("%d",a1);
        }
return 0;
}