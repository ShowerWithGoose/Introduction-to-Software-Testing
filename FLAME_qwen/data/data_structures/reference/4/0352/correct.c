#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char map[1000000][100];
int cmp(const void *A,const void *B)
{
	char *p=(char *)A;
	char *q=(char *)B;
	if(strcmp(p,q)>0)
		return 1;
	return -1;
}
int main()
{
	//cot map[10000];
	FILE *pr;
	pr=fopen("article.txt","r");
	char ch,tem[100]={'\0'};
	int i=0,j=0;
	ch=getc(pr);
	while(ch!=EOF)
	{
		if(ch>='A'&&ch<='Z')
			tem[i++]=ch+32;
		else if(ch>='a'&&ch<='z')
			tem[i++]=ch;
		else
		{
			i=0;
			if(tem[0]!='\0')
			{
				strcpy(map[j++],tem);
				//puts(tem);
			}
			memset(tem,'\0',100);
		}
		ch=getc(pr);
	}
	qsort(map,j,sizeof(map[0]),cmp);
	int time=1;
	for(i=0;i<j;i++)
	{
		if(strcmp(map[i],map[i+1])==0)
			time++;
		else
		{
			printf("%s %d\n",map[i],time);
			time=1;
		}
	}
	
	return 0;
}


