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
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but does not check if input ends after '-'. If the input ends right after '-', this causes undefined behavior by reading beyond available input. Also, it disrupts the sequential reading logic and may skip or misalign characters.]
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
                printf("%c%c", a[i-1], a[i]); // @@ [This prints '-' (as a[i-1]) and the next char, but the '-' was never printed before entering this block, so it's correct here. However, the logic of handling indices is fragile and assumes at least two prior characters exist, which may not be true if '-' appears at position 0 or 1.]
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