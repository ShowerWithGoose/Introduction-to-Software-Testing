#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct words{
	char word[30];
	int cnt;
	int flag;
}worddef;
int cmp(const void*pa,const void*pb)
{
	return strcmp((*(worddef*)pa).word,(*(worddef*)pb).word);
}
worddef get[5000];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char word0[30]={"\0"};
	int index=0;
	//∂¡»Î ˝æ› 
	while(~fscanf(in,"%s",word0))
	{
		int k=0;
		while(k<strlen(word0))
		{
			int m=0;
			while(isalpha(word0[k])==0&&k<strlen(word0))k++;
			while(isalpha(word0[k])&&k<strlen(word0))
			{
				get[index].word[m]=tolower(word0[k]);
				get[index].cnt=1;
				m++;
				k++;
			}
			get[index].word[m]='\0';
			index++;
		}
		for(int i=0;i<strlen(word0);i++)
		word0[i]='\0';
	}
	qsort(get,index,sizeof(get[0]),cmp);
	for(int i=0;i<index-1;i++)
	{
		int j=i+1;
		while(strcmp(get[i].word,get[j].word)==0&&j<index)
		{
			get[i].cnt++;
			get[j].flag=1;
			j++;
		}
		i=j-1;
	}
	for(int i=0;i<index;i++)
	if(get[i].flag==0&&get[i].word[0]!='\0')
	printf("%s %d\n",get[i].word,get[i].cnt);
	return 0;
}

