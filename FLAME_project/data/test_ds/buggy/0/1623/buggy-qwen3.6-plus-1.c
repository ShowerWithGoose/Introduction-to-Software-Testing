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
        return 3; // @@ Should explicitly check for [A-Z] and return 0 for other characters. Returning 3 for all others causes invalid chars like '-' to be incorrectly treated as uppercase.
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
} // @@ Missing 'return 0;' for the case when f(a) != f(b), which leads to undefined behavior.
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
                i=i+1; // @@ Should be i=i+2 to skip both the '-' and the end character after expansion. Otherwise, '-' is printed in the next iteration and the end character may be duplicated.
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}