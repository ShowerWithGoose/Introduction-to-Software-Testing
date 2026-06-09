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
        return 3; // @@ [ERROR: Should return 0 for characters outside the valid ranges, not 3. This causes non-alphanumeric and uppercase to be treated as the same type, leading to incorrect expansion decisions.]
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
    // @@ [ERROR: Missing return statement for the case when types differ. The function may return garbage, causing unpredictable behavior in the expansion condition.]
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
                    a[i]=a[i]+1; // @@ [ERROR: Modifying a[i] directly alters the array and disrupts subsequent iterations, especially with multiple dashes. Also fails to print the final character a[i+2].]
                }
                i=i+1; // @@ [ERROR: This increments i manually, then the for loop increments it again, effectively skipping the character after the dash. The logic does not correctly handle the loop index.]
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}