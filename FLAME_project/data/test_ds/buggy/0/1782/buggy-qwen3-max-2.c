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
            scanf("%c",&a[i]); @@ [The program reads an extra character after '-', but does not validate that there is a character before the '-'. If '-' appears at the start of input, a[i-2] will access invalid memory. Also, this approach disrupts the natural sequential reading and complicates indexing.]

            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            { @@ [The condition checks only upper bounds for digit/letter ranges but fails to ensure both characters are in the same valid category. For example, it allows '9' and 'Z' to pass the first part because both <= '9' is false but the logic is flawed; also, it doesn't check lower bound for the first character in digit case (e.g., a[i-2] >= '0'). This leads to incorrect expansion or missed expansions.]

                while(a[i-2] + j <= a[i])
                { @@ [This loop prints from a[i-2]+1 up to and including a[i], which duplicates the trailing character (a[i]) that will be printed again later when processing normally. The correct behavior is to expand between the two endpoints without duplicating the end.]

                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); @@ [This prints '-' and the next character when expansion isn't valid, but the '-' was already consumed and not printed earlier. However, the initial character before '-' (a[i-2]) was already printed in the else clause during its own turn, so printing a[i-1] (which is '-') and a[i] here is correct in structure, but due to flawed input handling above, indexing may be off.]

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