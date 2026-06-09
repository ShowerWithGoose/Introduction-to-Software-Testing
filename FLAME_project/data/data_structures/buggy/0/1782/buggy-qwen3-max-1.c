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
            scanf("%c",&a[i]); @@ [This reads an extra character after '-', but the input may have already ended or this disrupts the natural sequential reading of the string. Also, it assumes that every '-' is followed by another character, which may not be safe.]
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
                printf("%c%c", a[i-1], a[i]); @@ [This prints '-' and the next character when expansion shouldn't happen, but it should print the '-' as-is without consuming/altering the stream. However, the logic here misrepresents the original characters: a[i-1] is '-', and a[i] is the next char, so this prints "-X", which is correct in form, but the overall input reading is flawed due to manual scanf inside loop.]
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