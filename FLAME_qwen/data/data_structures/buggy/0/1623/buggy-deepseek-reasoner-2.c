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
        return 3; // @@ Error: Returns 3 for any character not digit or lowercase, including punctuation. Should check for uppercase [A-Z] and return 3 only for uppercase; for other characters (e.g., punctuation) should return 0 to prevent expansion.
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
    // @@ Error: Missing return for the case when f(a) != f(b). This leads to undefined behavior. Should add "return 0;" outside the if block.
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