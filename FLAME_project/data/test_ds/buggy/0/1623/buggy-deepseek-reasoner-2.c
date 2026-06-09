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
        return 3; // @@ [Error: This returns 3 for all non-digit, non-lowercase characters, incorrectly including uppercase and symbols as same type. Should check for uppercase separately and return 0 for others.]
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1; // @@ [Error: The function ff has no return value when condition false, leading to undefined behavior. Should return 0 for else.]
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
                i=i+1;
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}