#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word
{
	char str[200];
	int count;
};
char str1[10001];
char tmp[200];
struct word num[10001];
int cmp(const void *a, const void *b)
{
	return strcmp(((struct word*)a) -> str, ((struct word*)b) -> str);
}
int main()
{
	FILE *in;
	in = fopen("article.txt", "r");
	int j = 0, k = 0, flag = 0;
	while(fgets(str1, 10001, in) != NULL)
	{
		for(int i = 0; str1[i] != '\0'; i ++)
		{
			if(str1[i] <= 'z' && str1[i] >= 'a')
			{
				tmp[j] = str1[i];
				j++;
			}
			else if(str1[i] <= 'Z' && str1[i] >= 'A')
			{
				tmp[j] = str1[i] - 'A' + 'a';
				j++;
			}
			else
			{
				for(int p = 0; num[p].str[0] != '\0'; p ++)
				{
					if((strcmp(tmp,num[p].str) == 0) && tmp[0] != '\0')
					{
						flag = 1;
						num[p].count++;
						break;
					}
				}
				if(tmp[0] == '\0')
				{
					flag = -1;
				}
				if(flag == 0)
				{
					strcpy(num[k].str,tmp);
					num[k].count = 1;
					k ++;
				}	
				j = 0;
				memset(tmp, 0, sizeof(tmp));
				flag = 0;
			}
		}
		if(tmp[0] != '\0')
		{
			for(int p = 0; num[p].str[0] != '\0'; p ++)
				{
					if(strcmp(tmp,num[p].str) == 0)
					{
						flag = 1;
						num[p].count++;
						break;
					}
				}
				if(flag == 0)
				{
					strcpy(num[k].str,tmp);
					num[k].count = 1;
					k ++;
				}	
				j = 0;
				memset(tmp, 0, sizeof(tmp));
				flag = 0;
		}
	}
	qsort(num, k, sizeof(num[0]), cmp);
	for(int i = 0;num[i].str[0] != '\0'; i ++)
	{
		printf("%s %d\n", num[i].str, num[i].count);
	}
	fclose(in);
	return 0;
}


