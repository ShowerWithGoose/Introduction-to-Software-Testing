#include <stdio.h>
#include <string.h>
int main()
{
    char c[100] = {0};
    char k[1000] = {0};
    int j = 0;
    gets(c);
    for (int i = 0; i < strlen(c); i++, j++)
    {
        k[j] = c[i];
        if (c[i] == '-' && c[i - 1] < c[i + 1])
        {
            if (c[i - 1] >= 'a' && c[i + 1] <= 'z')
            {
                for (int x = 1; x < c[i + 1] - c[i - 1]; x++)
                {
                    k[j] = c[i - 1] + x;
                    j++;
                }
                j--;
            }
            else if (c[i - 1] >= 'A' && c[i + 1] <= 'Z')
            {
                for (int l = 1; l < c[i + 1] - c[i - 1]; l++)
                {
                    k[j] = c[i - 1] + l;
                    j++;
                }
                j--;
            }
            else if (c[i - 1] >= '0' && c[i + 1] <= '9')
            {
                for (int h = 1; h < c[i + 1] - c[i - 1]; h++)
                {
                    k[j] = c[i - 1] + h;
                    j++;
                }
                j--;
            }
        }
    }

    puts(k);
}


