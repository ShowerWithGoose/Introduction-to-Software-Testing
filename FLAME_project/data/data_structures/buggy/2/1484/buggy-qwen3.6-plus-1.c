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
    if(b1!='='){ // @@ The logic uses a single if-else structure instead of a loop, so it only processes the first few tokens and fails to handle the entire expression.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ Missing '&' before b3 in scanf, causing undefined behavior and incorrect input reading.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ Checking a3 != '0' compares the integer value to the ASCII character '0' (48), which is incorrect for checking division by zero. It should be a3 != 0. Also, this block doesn't loop for consecutive * or / operators.
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