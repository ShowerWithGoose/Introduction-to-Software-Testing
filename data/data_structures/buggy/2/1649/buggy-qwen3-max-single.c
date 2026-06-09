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
        if(b2=='*'||b2=='/') @@ [The program only handles one level of multiplication or division, but expressions may have consecutive * or / operators (e.g., 2 * 3 * 4). The reference uses a while loop here to handle multiple consecutive * or /, but this code uses only an if, causing incorrect precedence handling.]
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
        if(b1=='-') @@ [Using two separate if statements instead of else-if can cause incorrect behavior when b1 is '+', because both conditions might be checked (though in practice b1 won't be both '+' and '-', but more critically, this misses the case where b1 could be something else; however, the real issue is that after handling * and /, the next operator b2 might be '=' but the loop condition checks b1, leading to potential extra iteration. But the main logic flaw is the lack of while loop for * and /.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }