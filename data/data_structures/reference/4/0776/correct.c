#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 10000

FILE *in;
char c,temp[MAXN];
int n,lent;

struct vcbl
{
	char words[MAXN];
	int num;
}dtn[MAXN];

int compare(const void *a,const void *b)
{
	struct vcbl *p1=(struct vcbl *)a;
	struct vcbl *p2=(struct vcbl *)b;
	return strcmp(p1->words,p2->words);//–°µΩ¥Û≈≈–Ú 
}

int searchwords()
{
	int left=0;
	int right=n;
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		if(strcmp(dtn[mid].words,temp)==0)
		{
			dtn[mid].num++;
			return 1;
		}
		else if(strcmp(dtn[mid].words,temp)>0)
		{
			right=mid-1;
		}
		else if(strcmp(dtn[mid].words,temp)<0)
		{
			left=mid+1;
		}
	}
	return 0;
}

int main()
{
	in=fopen("article.txt","r");
	n=0;
	lent=0;
	while(fscanf(in,"%c",&c)!=EOF)
	{
//		printf("c is %c.\n",c);
		if(c>='a'&&c<='z')
		{
			temp[lent]=c;
			lent++;
		}
		else if(c>='A'&&c<='Z')
		{
			temp[lent]=c-'A'+'a';
			lent++;
		}
		else
		{
			temp[lent]='\0';
			if(searchwords()==0)
			{
				dtn[n].num=1;
				strcpy(dtn[n].words,temp);
				n++;
				qsort(dtn,n,sizeof(dtn[0]),compare);
			}
//			printf("temp is %s.\n",temp);
			lent=0;
			memset(temp,0,sizeof(temp));
		}
	}
	for(int i=1;i<n;i++)
	{
		printf("%s %d\n",dtn[i].words,dtn[i].num);
	}
	fclose(in);
	return 0;
}

