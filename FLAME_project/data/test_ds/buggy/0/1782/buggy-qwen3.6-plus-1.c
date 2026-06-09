#include<stdio.h>
#include<string.h>
int main()
{
    char a[10001];
    int i = 0, j = 1; // @@ j is not reset to 1 before each expansion, causing subsequent expansions to fail.
    while(scanf("%c", &a[i]) != EOF)
    {
        if(a[i] == '-')
        {

            i++;
            scanf("%c",&a[i]);
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ Missing >= '0' check for digits, and missing >= 'A'/'a' checks for the second character in uppercase/lowercase ranges.
            {
                while(a[i-2] + j <= a[i]) // @@ j should be reset to 1 before this loop for each new expansion.
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