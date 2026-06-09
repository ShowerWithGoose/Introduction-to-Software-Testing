#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct WORD
{
	char letters[50];
	int num;
}word;
int cmp(const void *a, const void *b)
{
	word *aa = a, *bb = b;
	if(strcmp(aa->letters, bb->letters) > 0)
		return 1;
	else 
		return -1;
}
word base[500];
int main()
{
	FILE *in;
	in = fopen("article.txt", "r");
	int i = 0, n = 0;
	char info[50] = {'\0'};
	char ch;
	while(fscanf(in, "%c", &ch) != EOF)
	{
		if(isalpha(ch))
		{
			info[i++] = tolower(ch);
			continue;
		}
		if(!isalpha(ch))
		{
			if(info[0] == '\0')
				continue;
			for(i = 0; i < n; i++)
			{
				if(!strcmp(info, base[i].letters))
				{
					base[i].num++;
					break;
				}
			}
			if(i == n)
			{
				strcpy(base[n].letters, info);
				base[n++].num++;
			}
			memset(info, '\0', 50);
			i = 0;
		}
	}
	qsort(base, n, sizeof(word), cmp);
	for(i = 0; i < n; i++)
		printf("%s %d\n", base[i].letters, base[i].num);
	fclose(in);
	return 0;
}


