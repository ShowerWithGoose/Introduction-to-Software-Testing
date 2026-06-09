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
    if(b1!='='){ // @@ The logic is flawed: it only processes one or two terms instead of looping through the entire expression until '=' is encountered. It lacks a while loop to handle multiple operators and operands.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ Error: missing '&' before b3 in scanf, causing undefined behavior and incorrect input reading.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ Error: checking a3 != '0' compares the integer value to the ASCII character '0' (48), not the integer 0. Should be a3 != 0. Also, this block doesn't handle subsequent * or / operations correctly without a loop.
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