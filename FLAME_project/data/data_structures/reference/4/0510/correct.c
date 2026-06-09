#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct wor
{
	char wo[100];
	int cnt;
}word;

int cmp(const void *p1,const void *p2)
{
	word *a=(word*)p1;
	word *b=(word*)p2;
	return strcmp(a->wo,b->wo);
}

int main()
{
	FILE *fin;
	fin=fopen("article.txt","r");
	char in[100]={'\0'},sto[100]={'\0'};
	word sort[500];
	int i=0,j=0,num=0,flag=0;
	for(i=0;i<500;i++)
	{
		sort[i].cnt=0;
		sort[i].wo[0]='\0';
	}
	
	char ch;
	while(fscanf(fin,"%c",&ch)!=EOF)
	{
		ch=tolower(ch);
		if(isalpha(ch))
		{
			memset(in,'\0',sizeof(in));
			i=0;
			while(isalpha(ch))
			{				
				ch=tolower(ch);
				in[i]=ch;
				i++;
				fscanf(fin,"%c",&ch);
			}
			
			
			
	
			flag=0;
			for(i=0;i<num;i++)
			{
				if(strcmp(in,sort[i].wo)==0)
				{
					sort[i].cnt++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				strcpy(sort[num].wo,in);
				sort[num].cnt=1;
				num++;
			}
		}
	}
	word* pp;
	pp=&sort[0];
	qsort(pp,num,sizeof(sort[0]),cmp);
	
	for(i=0;i<num;i++)
	{
		printf("%s %d\n",sort[i].wo,sort[i].cnt);
	}
	
	fclose(fin);
	return 0;
}

