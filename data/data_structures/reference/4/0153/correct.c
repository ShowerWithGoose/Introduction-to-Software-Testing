#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct articale{  
	char word[200];
	int n;     
};
typedef struct articale V;
char s[2000],x[2000],str;
int i,j,k,len,m=0;
V a[1000];
int stru(const void*p1,const void*p2);   
void DelRepeated(FILE *fp); 
void Output(FILE *fp);      
int main()
{	
	FILE *fp= fopen("article.txt","r");
    str=fgetc(fp);
	i=0;
	while(str!=EOF)
	{
		s[i]=str;
		i++;
		str=fgetc(fp);
	}
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(isalpha(s[i])) s[i]=tolower(s[i]);  
	}	
	for(i=0;i<len;i++)
	{
		if(isalpha(s[i]))  
		{
			for(j=i;j<len;j++)
			{
				if(!isalpha(s[j])) 
				{
					break;
				}
			}
			memset(x,0,sizeof(x));
			for(k=0;k<j-i;k++)
			{
				x[k]=s[i+k]; 
			}
			strcpy(a[m].word,x); 
			m++;
			i=j;
		}
		else	continue;
	}
	qsort(a,m,sizeof(V),stru);
	for(i=0;i<m;i++) a[i].n=1;
	for(i=0;i<m;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0)  
		{
			a[i+1].n+=a[i].n;
			a[i].n=0;
		}
	}
	qsort(a,m,sizeof(V),stru);
	for(i=0;i<m;i++)
	{
		if(a[i].n==0)
		{
			continue;
		}
		else
		{
			printf("%s %d\n",a[i].word,a[i].n);
		}
	}		
	fclose(fp);
	return 0;
}
int stru(const void*p1,const void*p2) 
{
	struct articale*a=(struct articale*)p1;
	struct articale *b=(struct articale*)p2;
	return strcmp(a->word,b->word);
}


