#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct word_num{
	char word[55];
	int  num;
} *WWord, Word;

int cmp_word(const void *p1, const void *p2){
	int ans;
	WWord w1 = (WWord) p1;
	WWord w2 = (WWord) p2;
	ans = strcmp(w1->word, w2->word);
	return ans;
}
main()
{
	FILE *fp;
	fp = fopen("article.txt", "r"); 
	if(fp == NULL)
	{
		return -1;
	}
	int i = 0, sum, j, l, k, u = 0;
	Word a[1000];
	char be[55];
	while(fscanf(fp, "%s", be) != EOF) 
	{
		for(j = 0; be[j] != '\0'; j++)
		{
			if(be[j] >= 'A' && be[j] <= 'Z')
			be[j] = tolower(be[j]);
		}
		u = 0;
		for(j = 0; be[j] != '\0'; j++)
		{
			if(be[j] >= 'a' && be[j] <= 'z')
			{
				a[i].word[u] = be[j];
				u++;
				if(be[j + 1] == '\0')
				{
					a[i].word[u] = '\0';
					a[i].num = 1;
					i++;
				}
			} 
			else if(be[j - 1] >= 'a' && be[j - 1] <= 'z')
			{
				a[i].word[u] = '\0';
				a[i].num = 1;
				i++;
				u = 0;
			}
		}
	}
	sum = i;
	for(i = 0; i < sum; i++)
	{
		if(a[i].num != 0)
		{
			for(j = 0; j < sum ; j++)
			{
				if(j != i && strcmp(a[i].word, a[j].word) == 0 && a[j].num == 1) 
				{
					a[i].num++;
					a[j].num--;
				}
			}
		}
		
	}
	for(i = 0; i < sum; i++)
	{
		if(a[i].num == 0)
		{
			for(j = i; j < sum; j++)
			{
				a[j] = a[j + 1];
			}
			i--;
			sum--;
		}
	}
	qsort(a, sum, sizeof(Word), cmp_word);
	for(i = 0; i < sum; i++)
	{
		printf("%s %d\n", a[i].word, a[i].num);
	}
	fclose(fp);
	return 0;
}

