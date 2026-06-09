#include <stdio.h>
int f(char x)
{
    if(x>='0'&&x<='9')
    {
        return 1;
    }
    if(x>='a'&&x<='z')
    {
        return 2;
    }
    else
        return 3;
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
}
int main()
{
    char a[10000];
    gets(a);
    int i;
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        if(a[i+1]=='-')
        {
            if(ff(a[i],a[i+2])==1&&(int)a[i+2]>(int) a[i])
            {
                while(a[i]!=a[i+2])
                {
                    printf("%c",a[i]);
                    a[i]=a[i]+1;
                }
                i=i+1; // @@ The loop increments i again at the end of the for statement, causing i to skip an extra character. This should be i=i+2 to skip the '-' and the next character, or restructure the loop.
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}