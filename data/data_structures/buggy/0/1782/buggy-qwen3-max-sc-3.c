#include<stdio.h>
#include<string.h>
int main()
{
    char a[10001];
    int i = 0, j = 1;
    while(scanf("%c", &a[i]) != EOF)
    {
        if(a[i] == '-')
        {

            i++;
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but does not validate that there is a character after '-'; also, it overwrites a[i] which was '-', breaking input sequence]
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ [Incorrect condition: e.g., a[i-2] <= '9' alone doesn't ensure it's a digit; should also check a[i-2] >= '0'. Same for letters. Also, mixing types like 'a' and 'Z' may pass incorrectly due to ASCII values]
            {
                while(a[i-2] + j <= a[i]) // @@ [Loop condition uses <=, which prints the end character again; should be < to avoid duplicating the end character already printed later or already present]
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--; // @@ [This decrements i, but logic for index management is flawed; original '-' and next char are not handled consistently with non-expansion cases]
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ [Prints '-' as a[i-1] and next char, but '-' was never printed before; this leads to missing or duplicated characters in output]
                i--;
            }

        }
        else
        {
            printf("%c", a[i]);
            //printf("%d", i);
            i++;
        }

    }
}