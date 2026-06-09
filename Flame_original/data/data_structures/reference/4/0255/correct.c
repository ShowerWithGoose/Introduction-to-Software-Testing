#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct ww{
	char word[100];
	int times;
} w,*pw;
w list[500];
int getword(FILE *fp, char a[]);
int cmp(const void *p1, const void *p2);

int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	if (fp==NULL)
	{
		printf("error");
		return -1;
	}
	int i=0,j,k,flag=0;
	while (getword(fp,list[i].word))
	{
		for (j=0;j<i;j++)
		{
			if (strcmp(list[j].word,list[i].word)==0)
			{
				list[j].times++;flag=1;break;
			}	
		}
		if (flag==0)
		{
			list[i].times=1;i++;
		}
		flag=0;
	}
	qsort(list,i,sizeof(list[0]),cmp);
	for (j=0;j<i;j++)
	{
		printf("%s %d\n",list[j].word,list[j].times);
	}
	fclose(fp);
	return 0;
 } 
int getword(FILE *fp, char a[])
{
	char tem[100]={0};
	int i=0,judge=0;
	do {
		tem[i]=fgetc(fp);
		if (isalpha(tem[i])==0&&tem[i]!=EOF)
			judge=0;
		else if (tem[i]==EOF)
			return 0;
		else
			judge=1;
	} while (judge==0);
	tem[i]=tolower(tem[i]);
	i++;
	while (isalpha(tem[i]=fgetc(fp)))
	{
		tem[i]=tolower(tem[i]);
		i++;
	}
	tem[i]='\0';
	strcpy(a,tem);
	return 1;
}
int cmp(const void *p1, const void *p2)
{
	pw a=(pw) p1;
	pw b=(pw) p2;
	return (strcmp(a->word,b->word));
}

