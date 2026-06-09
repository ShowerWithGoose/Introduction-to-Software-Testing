#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char str[105][20];
void replace(char str[][20], int n)
{
    char temp[20];
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
        }
    }
}
int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");
    char fu;
    int i = 0, j = 0, n = 0;
    fu=fgetc(fp); 
    while (fu!=EOF)
    {
        if (isalpha(fu))
        {
            str[i][j]=fu;
            j++;
        }

        else if (ispunct(fu)||isspace(fu)) 
        {
            str[i][j] = '\0';
            j = 0;
            i++;
        }

        fu = fgetc(fp);
    }
    n = i;
    for (i=0;i<n;i++) 
    {
        for (j=0;j<strlen(str[i]);j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }

    for (i=0;i<n;i++)
    {
        replace(str, n); 
    }

    int num[105] = {0}, flag = 0;

    for (i=0;i<n;i++)
    {
        flag = 0;
        num[i] = 1;
        for (j=i+1;j<n;j++)
        {
            if(!strcmp(str[i],str[j]))
            {
                num[i]++;
                str[j][0] = '\0';
                flag = 1;
            }

            if (str[j][0] == '\0')
            {
                continue;
            }

            else
            {
                if (flag == 1)
                {
                    i = j - 1;
                }
                break;
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
    return 0;
}




