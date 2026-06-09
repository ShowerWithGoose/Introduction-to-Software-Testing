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
            scanf("%c",&a[i]); // @@ If '-' is the first character, accessing a[i-2] in the subsequent condition will cause an out-of-bounds array access.
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ Missing lower bound check for digits (>= '0'), which may incorrectly match non-digit characters and cause invalid expansion.
            {
                while(a[i-2] + j <= a[i]) // @@ Variable j is not reset to 1 before this loop, causing incorrect expansion offsets for subsequent ranges.
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++; // @@ j should be reset to 1 after the expansion loop completes to ensure correct behavior for the next range.
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