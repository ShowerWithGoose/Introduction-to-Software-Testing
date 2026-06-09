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
        if(b1=='-') @@ [Using two separate if statements instead of else-if causes incorrect behavior when b1 is '+', because both conditions could be checked (though not both true), but more critically, this logic fails to handle operator precedence correctly in chained expressions and misses handling cases where after processing * or /, the next operator might be =; however, the primary logical error is that subtraction case runs even after addition if b1 were somehow both, which it can't be—but the real issue is that this structure doesn't loop for multiple * or / operations. The reference uses a while loop for consecutive * and /, but this code only handles one level, so expressions like 2 * 3 * 4 will fail.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }