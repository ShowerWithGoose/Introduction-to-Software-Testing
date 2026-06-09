#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word
{
	char w[114];
	int flag;
}s[1919],ss[1919];
int cmp(const void *a,const void *b)
{
	struct word *aa=(struct word *)a;
	struct word *bb=(struct word *)b;
	return strcmp(aa->w,bb->w);
}
int main()
{
	FILE *in=fopen("article.txt","r");
	char sen[514];
	int i=0,j=0,k=0;
	for(i=0;i<1919;i++)
	{
		s[i].flag=1;
		ss[i].flag=1;
	}
	while(fgets(sen,514,in)!=NULL)
	{
		int len=strlen(sen);
		for(i=0;i<len;i++)
		{
			if(sen[i]>='A'&&sen[i]<='Z')
			{
				s[j].w[k]=sen[i]+32;
				k++;
			}
			else if(sen[i]>='a'&&sen[i]<='z')
			{
				s[j].w[k]=sen[i];
				k++;
			}
			else
			{
				j++;
				k=0;
			}
		}
	}
	k=0;
	for(i=0;i<j;i++)
	if(s[i].w[0]>='a'&&s[i].w[0]<='z')
		strcpy(ss[k++].w,s[i].w);
	qsort(ss,k,sizeof(s[0]),cmp);
/*	for(i=0;i<j;i++)
		printf("%s\n",s[i].w);*/
	int t=k;
	k=0;
	for(i=0;i<t;i++)
		if(strcmp(ss[i].w,ss[i+1].w)!=0)
			printf("%s %d\n",ss[i].w,ss[i].flag);
		else
			{
				do{
					ss[i].flag++;
					k++;
				}while(strcmp(ss[i+k].w,ss[i+k+1].w)==0);
				printf("%s %d\n",ss[i].w,ss[i].flag);
				i=i+k;
				k=0;
			}
}

