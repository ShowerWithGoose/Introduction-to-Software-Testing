#include <stdio.h>
#include<stdlib.h>
char c[1000];
int i,k;
char j;
int main()
{
    scanf("%s", &c);
    while (c[i] != '\0') {
        if (c[i] == '-') {
            if (c[i - 1] >= 'a' && c[i - 1] <= 'z' && c[i + 1] >= 'a' && c[i + 1] <= 'z' && c[i - 1] < c[i + 1]) {
                for (j = c[i - 1] + 1; j < c[i + 1]; j++)
                    printf("%c", j);
            }
            else if (c[i - 1] >= 'A' && c[i - 1] <= 'Z' && c[i + 1] >= 'A' && c[i + 1] <= 'Z' && c[i - 1] < c[i + 1]) {
                for (j = c[i - 1] + 1; j < c[i + 1]; j++)
                    printf("%c", j);
            }
            else if (c[i - 1] >= '0' && c[i - 1] <= '9' && c[i + 1] >= '0' && c[i + 1] <= '9' && c[i - 1] < c[i + 1]) {
                for (j = c[i - 1] + 1; j < c[i + 1]; j++)
                    printf("%c", j);
            }
            else printf("%c", c[i]);
        }else
            printf("%c", c[i]);
        i++;
    }

    return 0;
}

