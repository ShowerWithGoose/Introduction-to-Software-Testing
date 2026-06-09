#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char str[105][20];
int num[105] = {0}, flag = 0;
int replace(char str[][20], int n)
{
    char temp[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
        }
    }
    return 0;
}
int main()
{
    FILE *fp = fopen("article.txt", "r");
    char c;
    int i = 0, j = 0, n = 0;
    while (fscanf(fp, "%c", &c) != EOF)
    {
        if (isalpha(c))
        {
            str[i][j] = c;
            j++;
        }
        else
        {
            str[i][j] = '\0';
            j = 0;
            i++;
        }
    }
    n = i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        replace(str, n);
    }
    for (i = 0; i < n; i++)
    {
        flag = 0;
        num[i] = 1;
        for (j = i + 1; j < n; j++)
        {
            if (!strcmp(str[i], str[j]))
            {
                num[i]++;
                str[j][0] = '\0';
                flag = 1;
            }
            if (str[j][0] != '\0')
            {
                if (flag == 1)
                {
                    i = j - 1;
                }
                break;
            }
            else
            {
                continue;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (str[i][0] != '\0')
        {
            printf("%s %d\n", str[i], num[i]);
        }
    }
    fclose(fp);
    return 0;
}
