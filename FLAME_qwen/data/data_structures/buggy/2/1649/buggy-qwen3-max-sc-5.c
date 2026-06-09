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
        if(b1=='-') @@ [Using two separate if statements instead of else-if causes incorrect behavior when b1 is '+', because both conditions could be checked and the second (b1 == '-') would be false, but in cases where operators change unexpectedly, it may lead to logic errors. However, the primary issue is that this program uses 'if' for both '+' and '-', so if b1 is '+', it adds, and then still checks if it's '-', which is harmless but inefficient. The real critical error is below.]
        a1-=a2; @@ [This line executes only if b1=='-', but due to missing braces and the prior if being separate, if b1 was '+', a1 gets added correctly, but if b1 was '-', it subtracts. However, the major flaw is that after handling * or /, the code does not continue to handle potential chains like 2*3*4 or 12/2/2 because it only reads one extra operand. The reference uses a while loop for consecutive * and /, but this buggy version uses only an if, so it fails on expressions with more than one consecutive * or /. This causes incorrect parsing of operator precedence for multiple multiplicative operations.]
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }