#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct words{
	char word[1024];
};
struct list{
	char gg[200];
	int num;
};
struct  words iwords[100];
struct list listwords[200];
void getwords(char a[], int *m)
{	
	int i = 0, j = *m, k = 0;
	int judge = 0;
	for(i = 0; i <= strlen(a) - 1; i++)
	{
		if(tolower(a[i]) >= 'a' && tolower(a[i]) <= 'z')
		{
			iwords[j].word[k++] = tolower(a[i]);
			judge = 1;
		}
		else if(!(tolower(a[i]) >= 'a' && tolower(a[i]) <= 'z') && judge == 1)
		{
			j++;
			judge = 0;
			k = 0;
		}
	}
	*m = j;
	return;
}
//void cleanthesame()
//void pprintf()
int main()
{
	FILE *in;
	int i = 0, j, m = 0, k;
	char sten[1024];
	in = fopen("article.txt", "r");
	while((fgets(sten, 1024, in))!=NULL)
	{	
		getwords(sten, &m);
		memset(sten, 0, sizeof(sten));
	}
	//for(i = 0; i <= m-1; i++)
	//{
	//	puts(iwords[i].word);
//	}
	char tmp[1024];
	for(i = 0; i <= m-1; i++)
		for(j = 0; j <= m-2; j++)
		{
			if(strcmp(iwords[j].word, iwords[j+1].word) > 0)
			{
				strcpy(tmp, iwords[j].word);
				strcpy(iwords[j].word, iwords[j+1].word);
				strcpy(iwords[j+1].word, tmp);
				
			}
		}
								//for(i = 0; i <= m-1; i++)
							//	{
							//			puts(iwords[i].word);
							//	}
		strcpy(listwords[0].gg, iwords[0].word);
		listwords[0].num = 1;
	for(i = 1, j = 0; i <= m -1; i++)
	{
		if(strcmp(iwords[i].word, iwords[i-1].word) == 0)
		{
			listwords[j].num ++;
		}
		else
		{
			strcpy(listwords[++j].gg, iwords[i].word);
			listwords[j].num = 1;
			
		}
	}
	for(i = 0; i <= j; i++)
	{
		for(k = 0; k <= strlen(listwords[i].gg)-1; k++)
		{
			printf("%c", listwords[i].gg[k]);
		}
		printf(" %d\n", listwords[i].num);
	}
	return 0;
	
}

