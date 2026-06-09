#include<stdio.h>
#include<string.h>
#include<stdlib.h>a
#include<ctype.h>
struct vocab{ 
	char word[200];
	int tim;  
};

typedef struct vocab V;
V a[1000];
char s[200],tmp[200],c;
int i,j,k,times=0;


int cmp(const void*p1,const void*p2) 
{
	struct vocab *a=(struct vocab*)p1;
	struct vocab *b=(struct vocab*)p2;
	return strcmp(a->word,b->word);
}
  
int main()
{	
	FILE *fp1 = fopen("article.txt","r");
	c=fgetc(fp1);
	i=0;
	while(c!=EOF)
	{
		s[i]=c;
		i++;
		c=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(((s[i])>='a' && (s[i])<='z' )|| ((s[i])>='A' && (s[i])<='Z') ) 
			s[i]=tolower(s[i]); 
	}
	
	for(i=0;i<strlen(s);i++)
	{
		if(((s[i])>='a' && (s[i])<='z' )|| ((s[i])>='A' && (s[i])<='Z') ) 
		{
			for(j=i;j<strlen(s);j++)
			{
				if(!isalpha(s[j]))
				{
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++)
			{
				tmp[k]=s[i+k];
			}
			strcpy(a[times].word,tmp);
			times++;
			i=j;
		}
		else	
			continue;
	}
	qsort(a,times,sizeof(V),cmp);
	
	for(i=0;i<times;i++) a[i].tim=1;
	
	for(i=0;i<times;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0)
		{
			a[i+1].tim+=a[i].tim;
			a[i].tim=0;
		}
	}
	qsort(a,times,sizeof(V),cmp);
	
	for(i=0;i<times;i++)
	{
		if(a[i].tim==0)
		{
			continue;
		}
		else
		{
			printf("%s %d\n",a[i].word,a[i].tim);
		}
	}
	
	return 0;
}

