#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char str[105][20];
void r(char str[][20], int n){
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
}
int main(){
	FILE *fp;
	fp=fopen("article.txt", "r");
	char c;
    int i = 0, j = 0, n = 0;
    c = fgetc(fp); 
    while (c != EOF)
    {
        if (isalpha(c))
        {
            str[i][j] = c;
            j++;
        }

        else if (ispunct(c) || isspace(c) /*ch == ' ' || ch == '.' || ch == ';' || ch == ',' || ch == ':' */)
        {
            str[i][j] = '\0';
            j = 0;
            i++;
        }

        c = fgetc(fp);
    }
    n = i;
    for (int i = 0; i < n; i++) //全变成小写
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        r(str, n); //排成字典序
    }

    int num[105] = {0}, flag = 0;

    for (int i = 0; i < n; i++) //查重，num为出现次数
    {
        flag = 0;
        num[i] = 1;
        for (int j = i + 1; j < n; j++)
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

    for (int i = 0; i < n; i++)
    {
        if (str[i][0] != '\0')
        {
            printf("%s %d\n", str[i], num[i]);
        }
    }
    fclose(fp);
    return 0;
}

