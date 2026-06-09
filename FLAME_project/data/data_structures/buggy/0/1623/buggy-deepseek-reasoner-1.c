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
        return 3; // @@ Error: For characters that are not digits or lowercase letters (e.g., uppercase, dash, space), this returns 3, but it should return 0 for invalid characters and 3 only for uppercase letters.
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
    // @@ Error: Missing return 0 for the case when types are different, leading to undefined behavior.
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