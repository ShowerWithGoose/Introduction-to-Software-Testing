#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

struct node{
	int times;
	char id[30];
}word[100000];

char c[1000];

int cmp(const void* a1,const void* b1)
{
	struct node* a=(struct node*)a1;
	struct node* b=(struct node*)b1;
	return strcmp(a->id,b->id);	
}

int main (void)
{
	int i,j,k,h;
	for(i=0;i<100000;i++)
		word[i].times=0;
	int cnt=0;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(c,1000,in)!=NULL)
	{
			for(i=0;c[i]!='\0';i++)
		{
			if(!isalpha(c[i]))
				continue;
			char tmp[30];
			for(j=i,k=0;isalpha(c[j]);j++,k++)
				tmp[k]=tolower(c[j]);
			tmp[k]='\0';
			int flag=1;
			for(h=0;h<cnt;h++)
			{
				if(strcmp(word[h].id,tmp)==0)
				{
					word[h].times++;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				word[cnt].times++;
				strcpy(word[cnt].id,tmp);
				cnt++;
			}
			i=j;
			if(c[i]=='\0')
				break;
		}
	}
	fclose(in);
	qsort(word,cnt,sizeof(struct node),cmp);
	for(i=0;i<cnt;i++)
		printf("%s %d\n",word[i].id,word[i].times);
    return 0;
}




