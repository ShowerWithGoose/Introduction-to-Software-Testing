#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>

int main()
{
    int x1, x2, x3;
    char a1, a2, a3;
    x1=0;
    a1='+';
    while(a1!='=')
    {
        scanf("%d %c", &x2, &a2);
        while(a2=='*'||a2=='/')
        {
            scanf("%d %c", &x3, &a3);
            if(a2=='*')
            {
                x2*=x3;
            }
            else if(a2=='/')
            {
                x2/=x3;
            }
            x2=x3; // @@ [Error: This line incorrectly overwrites the computed x2 with x3. It should instead update a2 = a3 to continue scanning the operator chain. The missing update of a2 causes an infinite loop because a2 remains '*', and the while condition never changes. Additionally, the computed result of multiplication/division is lost.]
        }
        if(a1=='+')
        {
            x1+=x2;
        }
        else if(a1=='-')
        {
            x1-=x2;
        }
        a1=a2;
    }
    printf("%d", x1);
    return 0;
}