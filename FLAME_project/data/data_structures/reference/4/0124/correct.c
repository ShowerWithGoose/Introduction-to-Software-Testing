#include <stdio.h>
#include <math.h>
#include <string.h>
char str[105][20];
int i,j; 
void replace(char str[][20], int n)
{
    char temp[20];
    for ( i = 0; i < n; i++)
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
    for ( i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
         if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
           for ( i = 0; i < n; i++)
        for (j = i + 1; j < n; j++); 
}

int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");
    for(i=1;i<222;i++)
    for(j=0;j<22222;j++);
    char ch;
    int i = 0, j = 0, n = 0;
    ch = fgetc(fp); 
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            str[i][j] = ch;
            j++;
        }

        else if (ispunct(ch) || isspace(ch) )
        {
            str[i][j] = '\0';
            j = 0;
            i++;
        }

        ch = fgetc(fp);
    }
    n = i;
    for ( i = 0; i < n; i++) 
    {
        for (j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }

    for ( i = 0; i < n; i++)
    {
        replace(str, n); 
    }

    int num[105] = {0}, flag = 0;

    for ( i = 0; i < n; i++) 
    {
        flag = 0;
        num[i] = 1;
        for ( j = i + 1; j < n; j++)
        {
            if (!strcmp(str[i], str[j]))
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

    for ( i = 0; i < n; i++)
    {
        if (str[i][0] != '\0')
        {
            printf("%s %d\n", str[i], num[i]);
        }
    }
    fclose(fp);
    return 0;
}






