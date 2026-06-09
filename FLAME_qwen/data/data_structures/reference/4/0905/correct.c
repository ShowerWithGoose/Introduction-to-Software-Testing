#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char str[105][20];
void replace(char str[][20], int n)
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
}

int main()
{
    FILE *fp;
    fp = fopen("article.txt", "r");

    char ch;
    int i = 0, j = 0, n = 0;
    ch = fgetc(fp); //输入
    while (ch != EOF)
    {
		if(ch>='A'&&ch<='Z')
		{
			ch+=32;
			str[i][j]=ch;
			j++;
		}
		else if(ch>='a'&&ch<='z')
		{
			str[i][j]=ch;
			j++;
		}
		else{
			j=0;i++;
		}
		ch=fgetc(fp);
	}
		n=i;
	replace(str,n);
	int num[105] = {0}, flag = 0;

    for (i = 0; i < n; i++) //查重，num为出现次数
    {
        flag = 0;
        num[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (!strcmp(str[i], str[j]))
            {
                num[i]++;
                //strcpy(str[j], '\0');
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
