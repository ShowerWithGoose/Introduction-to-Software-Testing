#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 1024
char line[maxnum];
struct alph{
	char s[20];
	int n;
}list[500];
char str[20];
void swap(int,int);
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int i,j=0,k=0,q,flag;
	for(i=0;i<500;i++)
	list[i].n=0;
	while(fgets(line,maxnum-1,in)!=NULL)
	{
		int len=strlen(line);
		for(i=0;i<len;i++)
		{
			j=0,flag=0;
			char str[20];
			while(tolower(line[i])<='z'&&tolower(line[i])>='a')
			{
				str[j]=tolower(line[i]);
				j++;
				i++;
				flag=1;
			}
			if(flag==1)
			{
			str[j]='\0';
			for(q=0;q<k;q++)
			{
				if(strcmp(list[q].s,str)==0)
				{
					list[q].n++;
					break;
				}
			}
			if(q>=k)
			{
			strcpy(list[k].s,str);
			list[k].n++;
			k++;
			}
			}
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=0;j<k-1-i;j++)
		{
			if(strcmp(list[j].s,list[j+1].s)>0)
			swap(j,j+1);
		}
	}
	for(i=0;i<k;i++)
	printf("%s %d\n",list[i].s,list[i].n);
	return 0;
}
void swap(int a,int b)
{
	char manu[20];
	int m;
	strcpy(manu,list[b].s);
	strcpy(list[b].s,list[a].s);
	strcpy(list[a].s,manu);
	m=list[b].n;
	list[b].n=list[a].n;
	list[a].n=m;
}

