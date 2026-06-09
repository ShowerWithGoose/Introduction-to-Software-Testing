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
    if(b1!='='){ // @@ [This 'if' should be a 'while' loop to process the entire expression until '=' is encountered. Using 'if' only processes the first token and exits.]
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ [Missing '&' before b3; should be &b3 to correctly read the character into b3.]
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ [The condition 'a3 != '0'' compares integer a3 with character '0'; it should just check for division by zero as 'a3 != 0'. Also, problem states expression is always valid, so this check is unnecessary and incorrectly implemented.]
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
        else if(b1=='=') // @@ [This block is unreachable because b1 is initialized to '+' and never becomes '=' due to incorrect loop structure. Also, output should happen after full expression processing, not inside an else-if.]
        {
            printf("%d",a1);
        }
return 0;
}