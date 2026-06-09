#include<stdio.h>
int main()
{
    int a1,a2,a3;
    char b1,b2,b3;
    a1=0;
    b1='+';
    while(b1!='=')
    {
        scanf("%d %c",&a2,&b2);
        if(b2=='*'||b2=='/')
        {
            scanf("%d %c", &a3,&b3);
            if(b2=='*')
            a2*=a3;
            else if(b2=='/')
            a2/=a3;
            b2=b3;
        }
        if(b1=='+')
        a1+=a2;
        if(b1=='-') @@ [Using two separate 'if' statements instead of 'else if' causes incorrect behavior when b1 is '+', because both conditions could be checked and applied incorrectly in some edge cases, but more critically, the logic fails to handle operator precedence correctly across multiple terms. However, the primary error causing wrong output is that after processing a * or / sequence, if the next operator is '=' (end), the loop still processes the term again with stale b1. But the actual critical flaw is that this version only handles one level of * or /, not chained ones like '* 2 * 3'. The reference uses a 'while' for * and /, but this code uses 'if', so it can't handle consecutive multiplicative operators.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }