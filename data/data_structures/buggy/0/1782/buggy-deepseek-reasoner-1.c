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
            scanf("%c",&a[i]); // @@ [No EOF check; if input ends with '-', undefined behavior]
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ [Missing lower bound checks for a[i] in digit and lowercase parts, and for a[i-2] in digit part]
            {
                while(a[i-2] + j <= a[i]) // @@ [j not reset for each '-' occurrence, causing incorrect expansion when multiple '-' present]
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]);
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