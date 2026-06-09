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
        return 3; // @@ [This incorrectly returns 3 for non-alphanumeric characters and uppercase letters. It should only return 3 for uppercase letters (A-Z), and 0 for invalid characters. This causes incorrect type matching in ff().]
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1;
    }
    // @@ [Missing return statement when f(a) != f(b). Function should return 0 in that case, but currently returns undefined value.]
}
int main()
{
    char a[10000];
    gets(a); // @@ [Use of unsafe gets() function; though not directly causing logic error, it's deprecated. More critically, the loop logic below has multiple flaws.]
    int i;
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        if(a[i+1]=='-') // @@ [This condition is checked immediately after the previous one, leading to double handling when a[i+1] is '-'. Also, when at last character, a[i+1] may be '\0', and a[i+2] is out-of-bounds.]
        {
            if(ff(a[i],a[i+2])==1&&(int)a[i+2]>(int) a[i]) // @@ [Accesses a[i+2] without checking if i+2 is within bounds (i.e., before '\0'). This leads to undefined behavior on strings ending with '-' or having '-' at second last position.]
            {
                while(a[i]!=a[i+2])
                {
                    printf("%c",a[i]);
                    a[i]=a[i]+1; // @@ [Modifying the input array during iteration changes the original character, which affects future comparisons and output. Also, the final character a[i+2] is never printed.]
                }
                i=i+1; // @@ [Only skips one extra character, but should skip two (the '-' and the next char). This causes misalignment in parsing the rest of the string.]
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}