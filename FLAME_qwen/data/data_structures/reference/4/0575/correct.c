#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct word
{
	char c[100];
	int num;
}w[1000];

char load[200];
int cmp(const void *p1,const void *p2)
{
	if((*(struct word*)p1).c[0]=='\0')
	{
		return 1;
	}
	return strcmp((*(struct word*)p1).c,(*(struct word*)p2).c);
}

int main()
{
	int i,j,k;
	for(i=0;i<1000;i++)
	{
		memset(w[i].c,'\0',sizeof(w[i].c));
		w[i].num=0;
	}
	int max,l;
	char now[50];
	FILE *f;
	f=fopen("article.txt","r");
	while(fgets(load,200,f))
	{
		i=0;
		l=strlen(load);
		while(i<l)
		{
			memset(now,'\0',sizeof(now));
			while(isalpha(load[i])==0&&i<l)
			{
				i++;
			}
			for(j=0;isalpha(load[i])!=0&&i<l;i++)
			{
				now[j]=tolower(load[i]);
				j++;
			}
			while(isalpha(load[i])==0&&i<l)
			{
				i++;
			}
			for(k=0;k<1000&&w[k].num!=0;k++)
			{
				if(strcmp(w[k].c,now)==0)
				{
					w[k].num++;
					break;
				}
			}
			if(w[k].num==0)
			{
				strcat(w[k].c,now);
				w[k].num++;
				max=k;
			}
			
		}
		memset(load,'\0',sizeof(load));
	}
	qsort(w,max+1,sizeof(w[0]),cmp);
	qsort(w,max+1,sizeof(w[0]),cmp);
	for(i=0;i<max+1;i++)
	{
		if(w[i].c[0]!='\0')
		printf("%s %d\n",w[i].c,w[i].num);
	}
	fclose(f);
	return 0;
}

