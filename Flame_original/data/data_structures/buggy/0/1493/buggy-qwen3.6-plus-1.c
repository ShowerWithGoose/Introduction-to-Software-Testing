#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a); // @@ gets is removed in the C11 standard and will cause a compilation error in modern compilers; use fgets(a, sizeof(a), stdin) instead.

    printf("%c", a[0]);
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1])
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ Logical error: incomplete range check. Only checks lower bound for left char and upper bound for right char, allowing mixed types (e.g., 'a' and 'R'). Should check a[i-1]<='z' && a[i+1]>='a'.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ Logical error: incomplete range check for uppercase letters. Missing a[i-1]<='Z' && a[i+1]>='A'.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ Logical error: incomplete range check for digits. Missing a[i-1]<='9' && a[i+1]>='0'.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        } // @@ Logical error: if '-' is found but types do not match, the '-' character is not printed. An else clause is needed here to print a[i] when expansion conditions fail.

        else
        {
            printf("%c", a[i]);
        }

    }


    return 0;
}