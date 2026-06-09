#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
struct count{
	int times;
	char word[500];
}p[1000];
int cmp(const void*p1,const void*p2) 
{
	struct count *a=(struct count*)p1;
	struct count *b=(struct count*)p2;
	return strcmp(a->word,b->word);
}
int main()
{char c;
char a[1000];
int i=0,m=0,n=0;
	FILE *fp1=fopen("article.txt","r");
	c=fgetc(fp1);
	
	while(c!=EOF)
	{if(c>='A'&&c<='Z')
	c=c-'A'+'a';
	a[i++]=c;
	c=fgetc(fp1);
	}
	
	i=0;
	while(i<strlen(a))
	{if(a[i]>='a'&&a[i]<='z')
	{while(a[i]>='a'&&a[i]<='z')
	{p[m].word[n]=a[i];
	n++;
	i++;
	}
	m++;
	n=0;
	}
	else
	i++;
	}
	

qsort(p,m,sizeof(p[0]),cmp);



for(i=0;i<m;i++)
p[i].times=1;
	for(i=0;i<m;i++)
if(strcmp(p[i].word,p[i+1].word)==0)
{p[i+1].times+=p[i].times;
p[i].times=0;
}
for(i=0;i<m;i++)
{if(p[i].times!=0)
printf("%s %d\n",p[i].word,p[i].times);
else
continue;} 
	return 0;
}

