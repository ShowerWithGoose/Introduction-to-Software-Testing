#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[1600];
char s1[1600];
int flag = 0;
typedef struct ar
{
	char s[1000];
	int x;
}hash,*h;

int cmp(const void* a, const void* b)
{
	hash* aa = (hash*)a;
	hash* bb = (hash*)b;
	return strcmp(aa->s, bb->s);
}

hash arr[5000];
int num = 0;
int flag1 = 0;
int main()
{
	FILE* in;
	in = fopen("article.txt", "r");
	while (fgets(s,1600,in) != NULL)
	{
		int a = strlen(s);
		for (int i = 0;i < a;i++)
		{
			s[i] = tolower(s[i]);
		}
		for (int i = 0;i < a;i++)
		{
			memset(s1, 0, sizeof(s1));
			int count = 0;
			while (s[i] >= 'a' && s[i] <= 'z')
			{
				s1[count] = s[i];
				count++;
				i ++;
				flag = 1;
			}
			if (flag == 1)
			{
				for (int j = 0;j < num;j++)
				{
					if (strcmp(s1, arr[j].s) == 0)
					{
						arr[j].x++;
						flag1 = 1;
					}
				}
				if (flag1 == 0)
				{
					strcpy(arr[num].s, s1);
					arr[num].x = 1;
					num++;
				}
				flag1 = 0;
				flag = 0;
			}
		}
	}
	qsort(arr, num, sizeof(hash), cmp);
	for (int i = 0;i < num;i++)
	{
		printf("%s %d\n", arr[i].s, arr[i].x);
	}
	fclose(in);
	return 0;
}


