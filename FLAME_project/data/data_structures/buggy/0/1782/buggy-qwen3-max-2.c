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
            scanf("%c",&a[i]);
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
                printf("%c%c", a[i-1], a[i]); @@ [This prints '-' followed by next char when expansion shouldn't happen, but it should print the '-' and next char as-is without skipping logic; however, more critically, the condition above fails to ensure both characters are of the same valid type (e.g., digit-digit, upper-upper, lower-lower), because it checks only upper bounds without lower bounds for digits and mixes types. For example, 'uB-F' leads to processing 'B-F' correctly, but the initial 'a-u' is processed, then the code mishandles the transition. Also, after printing expanded sequence, the loop doesn't skip the '-' and next char properly in all cases. But the main error is in the condition: for digits, it doesn't check a[i-2] >= '0' and a[i] >= '0', so something like '-5' where a[i-2] is non-digit could pass the first part incorrectly. Similarly, uppercase check misses a[i] >= 'A', and lowercase misses a[i] >= 'a'. This causes invalid expansions or missed expansions.]
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