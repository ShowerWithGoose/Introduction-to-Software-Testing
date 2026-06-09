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
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but does not check if input ends (EOF) after '-', leading to undefined behavior or incorrect indexing like a[i-2] when i < 2]
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            {
                while(a[i-2] + j <= a[i])
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ [When expansion condition fails, it prints '-' (a[i-1]) and next char, but original '-' was already consumed and not printed before; logic misaligns with expected output format]
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