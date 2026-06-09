#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct list{
	char s[100];
	int count;
}l[2000];
int main()
{
	int i=0,j=0,n;
	int flag;
	FILE *fp;
	fp=fopen("article.txt","r");
	char c;
	c=fgetc(fp);
	while(c!=EOF)
	{
		if(isalpha(c))
		{
			l[i].s[j]=c;
			j++;
		}
		else if(ispunct(c) || isspace(c))
		{
			l[i].s[j]='\0';
			j=0;
			i++;
		}
		c=fgetc(fp);
	}
	n=i;
	   for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < strlen(l[i].s); j++)
        {
            l[i].s[j] = tolower(l[i].s[j]);
        }
    }
	char temp[1000];
	for(int p=0;p<n;p++)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(l[i].s, l[j].s) > 0)
            {
                strcpy(temp, l[j].s);
                strcpy(l[j].s, l[i].s);
                strcpy(l[i].s, temp);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
    	l[i].count=1;
	}
    for (int i = 0; i < n; i++) 
    {
        flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (!strcmp(l[i].s, l[j].s))
            {
                l[i].count++;
                l[j].s[0] = '\0';
                flag = 1;
            }

            if (l[j].s[0] == '\0')
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
	for(int i=0;i<n;i++)
	{
		if(l[i].s[0]!='\0')
		{
			printf("%s %d\n",l[i].s,l[i].count);
		}
	}
	fclose(fp);
	return 0;
}


