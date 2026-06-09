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
        if(b2=='*'||b2=='/') @@ [This should be a while loop, not an if statement, to handle consecutive * and / operators correctly. The current code only processes one multiplication or division per term, failing on expressions like "2*3*4".]
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
        if(b1=='-') @@ [Using two separate if statements can cause incorrect behavior when b1 is '+', because both conditions are checked. It should be else if to ensure only one branch executes. However, since b1 can only be '+' or '-' at this point (due to the logic), this may not be the primary error. The main issue is the missing loop for * and /.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }