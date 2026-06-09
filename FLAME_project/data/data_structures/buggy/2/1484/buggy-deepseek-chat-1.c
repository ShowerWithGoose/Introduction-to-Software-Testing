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
    if(b1!='='){ // @@ This should be a while loop, not an if statement, to process the entire expression until '=' is encountered.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){ // @@ This logic is incorrect; it only handles one multiplication/division, but the expression may have multiple consecutive * or / operators (e.g., 1 * 2 * 3). The reference program uses a while loop here.
            scanf("%d %c",&a3,b3); // @@ Missing & before b3; should be &b3.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ a3 is an integer, not a character; comparing a3!='0' is incorrect. It should check if a3 != 0 to avoid division by zero, but the problem guarantees valid input, so this check is unnecessary.
                a2/=a3;
            }
            b2=b3;    
        }
        else if(b2=='+' || b2=='-'){ // @@ This else-if is misplaced; the code should handle addition/subtraction after processing all multiplication/division in the current term, not only when b2 is + or -.
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