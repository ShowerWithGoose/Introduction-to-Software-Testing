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
        if(b2=='*'||b2=='/') @@ [This should be a while loop, not an if statement, to handle consecutive * and / operators correctly. Using 'if' only processes one multiplication/division operation, failing on expressions like "2*3*4" or "12/2/2".]
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
        if(b1=='-') @@ [Using two separate 'if' statements instead of 'else if' can cause incorrect behavior when b1 is '+', because both conditions might be checked (though not logically possible here), but more critically, this structure doesn't match the reference logic which uses else-if for mutual exclusion. However, the main error is the missing loop for * and /.]
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }