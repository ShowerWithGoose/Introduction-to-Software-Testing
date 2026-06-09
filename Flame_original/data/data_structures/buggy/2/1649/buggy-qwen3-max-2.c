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
        if(b1=='-') @@ [Using two separate if statements instead of else-if causes incorrect behavior when b1 is '+', because both conditions could be checked and the second (b1 == '-') would incorrectly subtract a2 if b1 were somehow both, but more critically, this logic fails to handle operator precedence correctly in chained expressions and misses handling cases where after processing * or /, the next operator might be =, leading to reading beyond input. However, the primary logical error is that subtraction case should be in an else-if to avoid double application, but the bigger issue is that the inner loop for * and / is not a loop—it only handles one level of multiplication/division, failing on expressions like 2*3*4. The reference uses a while loop here, but this code uses a single if, so it cannot handle consecutive * or / operators.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }