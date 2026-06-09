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
    if(b1!='='){ // @@ Should be while(b1!='=') to process the entire expression until the ending '='.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ Missing '&' before b3; should be &b3.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ Condition a3!='0' compares char '0' (ASCII 48), not integer 0; should be a3!=0.
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
        else if(b1=='=') // @@ This else if is unreachable because b1 is never '=' after the if block; the whole structure should be a while loop, not an if-else.
        {
            printf("%d",a1);
        }
return 0;
}