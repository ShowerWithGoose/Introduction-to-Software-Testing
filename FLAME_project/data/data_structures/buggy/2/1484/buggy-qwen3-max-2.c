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
    if(b1!='='){ @@ [The program uses an 'if' instead of a 'while' loop, so it only processes the first token and does not continue reading the rest of the expression. This causes incomplete evaluation of the input.]
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); @@ [Missing '&' before b3 in scanf; should be &b3. This leads to undefined behavior as scanf writes to an incorrect memory location.]
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ @@ [The condition 'a3 != '0'' compares an integer a3 with character '0'; it should just check a3 != 0 to avoid division by zero, but the problem states the expression is always valid, so this check is unnecessary and incorrectly implemented.]
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