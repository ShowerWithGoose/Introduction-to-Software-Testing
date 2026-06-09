#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct word{
	char word1[203];
	int cnt;
};
int cmp(const void *p1, const void *p2);
typedef struct word V;
V a[1000];
int main()
{
	char s[200], temp[200], ch;
	int i, j, k, m, n;
	FILE *fp;
	fp = fopen("article.txt", "r");
	ch = fgetc(fp);
	i=0;
	while(ch!=EOF)
	{
		s[i] = ch;
		i++;
		ch = fgetc(fp);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))
		{
			for(j=i;j<strlen(s);j++)
			{
				if(!isalpha(s[j]))
				break;
			}
		memset(temp,0,sizeof(temp));
		for(k=0;k<j-i;k++)
		temp[k]=s[i+k];
		strcpy(a[n].word1, temp);
		n++;
		i=j;
		}
		else
		continue;
	}
	qsort(a, n, sizeof(V), cmp);
	for(i=0;i<n;i++)
	{
		a[i].cnt=1;
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].word1, a[i+1].word1)==0)
		{
			a[i+1].cnt += a[i].cnt;
			a[i].cnt = 0;
		}
	}
	qsort(a, n, sizeof(V), cmp);
	for(i=0;i<n;i++)
	{
		if(a[i].cnt==0)
		{
			continue;
		}
		else 
		{
			printf("%s %d\n", a[i].word1, a[i].cnt);
		}
	}
	return 0;
}
int cmp(const void* p1, const void* p2)
{
	struct word *a = (struct word*)p1;
	struct word *b = (struct word*)p2;
	return strcmp(a->word1, b->word1);
 } 



