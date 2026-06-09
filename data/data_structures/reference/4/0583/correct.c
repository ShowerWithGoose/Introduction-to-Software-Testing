#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void bubble(char str[110][30], int n)
{
	char tmp[30];
	for(int i = 0;i < n-1;i++)
	{
		for(int j = 0;j < n-i-1;j++)
		{
			if(strcmp(str[j],str[j+1]) > 0)
			{
				strcpy(tmp,str[j+1]);
				strcpy(str[j+1],str[j]);
				strcpy(str[j],tmp);
			}
		}
	}
}
int main()
{
	FILE *input = fopen("article.txt", "r");
	char ch;
	char str[110][30];
	int i,j;
	int n;
	int len;
	int num[110] = {0};
	int op[110] = {0};
	ch = fgetc(input);
	i = 0;
	j = 0;
	while(ch != EOF)
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			str[i][j] = ch;
			j++;
		}
		else
		{
			str[i][j] = '\0';
			j = 0;
			i++;
		}
		ch = fgetc(input);
	}
	n = i;
	i = 0;
	while(i < n)
	{
		len = strlen(str[i]);
		j = 0;
		while(j < len)
		{
			str[i][j] = tolower(str[i][j]);
			j++;
		}
		i++;
	}
	bubble(str,n);
	i = 0;
	j = 0;
	while(i < n)
	{
		if(op[i] == 1)
		{
			i++;
			continue;
		}
		j = i + 1;
		while(j < n)
		{
			if(strcmp(str[i],str[j]) == 0)
			{
				op[j] = 1;
				num[i]++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while(i < n)
	{
		if(op[i] == 0&&str[i][0]!='\0')
		{
			printf("%s %d\n",str[i],num[i]+1);
		}
		i++;
	}
	fclose(input);
	return 0;
}
