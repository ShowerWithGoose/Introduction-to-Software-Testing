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
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but does not validate that there is a character after '-'; if input ends with '-', this causes undefined behavior or incorrect indexing. Also, the logic assumes every '-' is followed by another character, which may not be true.]

            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            { // @@ [The condition checks only upper bounds for digit/letter types but fails to ensure both characters are of the same category. For example, '0' <= '9' and 'a' <= 'z', but comparing '0' and 'a' would incorrectly pass part of the condition. Also, missing lower bound check for digits (e.g., a[i-2] >= '0').]

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
                printf("%c%c", a[i-1], a[i]); // @@ [This prints '-' and the next character when expansion isn't valid, but the '-' was already consumed and not printed earlier. The initial character before '-' was printed in the else clause of the outer if, so printing a[i-1] (which is '-') again leads to duplication or misordering.]
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