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
        return 3; // @@ [This function returns 3 for uppercase letters, but also for any non-digit/non-lowercase character (e.g., symbols), which may lead to incorrect type matching in ff(). However, the main logic error is elsewhere.]
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    } // @@ [Missing return statement when f(a) != f(b); this leads to undefined behavior as the function may return garbage values.]
}
int main()
{
    char a[10000];
    gets(a); // @@ [Use of unsafe gets() function which is deprecated and may cause buffer overflow; however, the immediate logical errors are more critical.]
    int i;
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        if(a[i+1]=='-') // @@ [Logic flaw: This condition overlaps with the previous if; when a[i+1] is '-', both blocks may execute incorrectly. Also, it checks a[i+1] before ensuring a[i+2] exists, risking out-of-bounds access.]
        {
            if(ff(a[i],a[i+2])==1&&(int)a[i+2]>(int) a[i]) // @@ [Accesses a[i+2] without checking if i+2 is within string bounds; may read beyond null terminator. Also, ff() has undefined behavior due to missing return.]
            {
                while(a[i]!=a[i+2])
                {
                    printf("%c",a[i]);
                    a[i]=a[i]+1; // @@ [Modifying the input array during iteration alters future comparisons and breaks loop logic; also, after incrementing a[i], the loop condition may never terminate if a[i+2] was changed or if types differ.]
                }
                i=i+1; // @@ [Skips only one character after expansion, but should skip two (the '-' and the next char), leading to duplicate output or missed characters.]
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}