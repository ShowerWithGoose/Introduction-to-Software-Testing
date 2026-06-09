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
    if(b1!='='){ // @@ This condition is always true, but the logic is flawed: the program only reads one operator and one number, then exits without processing the full expression. The loop structure from the reference program is missing.
        scanf("%d %c",&a2,&b2);
        if(b2=='*' || b2=='/'){
            scanf("%d %c",&a3,b3); // @@ Missing & before b3; should be &b3. Also, this scanf does not handle the case where b2 is '/' and a3 is 0 (division by zero), but the check a3!='0' is incorrect because a3 is an integer, not a character.
            if(b2=='*'){
                a2*=a3;
            }
            else if(b2=='/' && a3!='0'){ // @@ a3!='0' compares integer a3 with character '0' (ASCII 48), which is logically wrong. Should be a3 != 0.
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