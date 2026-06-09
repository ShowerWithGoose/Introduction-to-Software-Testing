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