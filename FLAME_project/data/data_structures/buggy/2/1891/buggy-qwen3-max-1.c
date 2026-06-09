#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a=0;
    x='+';
    scanf("%d %c",&b,&y);
    while(1)
    {
        if(y=='*'||y=='/')
        {
            scanf("%d %c",&c,&z);
            if(y=='*') b=b*c;
            else if(y=='/') b=b/c;
            
            y=z;
        }
        if(y=='+'||y=='-')
        {
            if(y=='+') a=a+b;
            else if(y=='-') a=a-b;
            
            x=y;
            scanf("%d %c",&b,&y);
        }
        if(y=='=')
        {
            if(x=='+') a=a+b; // @@ [This uses the previous operator 'x' instead of the current term's sign. However, when '=' is encountered right after a term (e.g., at the end), the last term 'b' hasn't been applied yet, but the logic here assumes 'x' is the operator before 'b'. In reality, for the final term, its sign is determined by the operator that came before it, which is stored in 'y' from the prior step — but in this code, when we read the last number and '=', we never process it through the '+'/'-' block, so 'x' is outdated.]
            else if(x=='-') a=a-b; // @@ [Same issue as above: using stale operator 'x' instead of correctly associating the last term with its preceding operator. The last term is read in the '+'/'-' block, but if the expression ends right after a multiplication/division chain, it never enters that block again, so the final 'b' is not added/subtracted properly.]
            
            printf("%d\n",a);
            break;
        }
    }
    return 0;
}