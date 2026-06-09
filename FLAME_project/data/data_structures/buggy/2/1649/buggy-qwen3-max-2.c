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
        } // @@ [This only handles one level of * or /, but consecutive * and / operations (like / / * * ...) require repeated processing until a + or - or = is encountered. The reference program uses a while loop here to handle all consecutive * and / operators, but this code uses only an if, causing premature termination of operator precedence handling.]
        if(b1=='+')
        a1+=a2;
        if(b1=='-')
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }