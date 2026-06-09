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
    if(b1!='='){
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ Missing '&' before 'b3' in scanf, which expects a pointer to char. This causes a compilation error.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ Compares integer 'a3' with character literal '0' instead of integer 0. Should be 'a3 != 0'.
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
        else if(b1=='=') // @@ Unreachable code block because 'b1' is initialized to '+' and never updated. Also, the program lacks a loop to continuously read and process the expression until '='.
        {
            printf("%d",a1);
        }
return 0 ;
}