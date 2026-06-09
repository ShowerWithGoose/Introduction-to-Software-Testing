#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct voc{  
	char word[400];
	int times;      
};
typedef struct voc v;
int i,j,k,cnt=0;
char s[300],tmp[300],ch;
v a[2000];
int cmp(const void*p1,const void*p2) 
{
	struct voc *a=(struct voc*)p1;
	struct voc *b=(struct voc*)p2;
	return strcmp(a->word,b->word);
}
void Get(FILE *fp1)
{
	ch=fgetc(fp1);
	i=0;
	while(ch!=EOF)
	{
		s[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) 
		{
			s[i]=tolower(s[i]);
		} 
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))  
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
			strcpy(a[cnt].word,tmp); 
			cnt++;
			i=j;
		}
		
	}
	qsort(a,cnt,sizeof(v),cmp); 
	for(i=0;i<cnt;i++) a[i].times=1;
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0) 
		{
			a[i+1].times+=a[i].times; 
			a[i].times=0;
		}
	}
	qsort(a,cnt,sizeof(v),cmp);
	for(i=0;i<cnt;i++)
	{
		if(a[i].times!=0)
		
		{
			printf("%s %d\n",a[i].word,a[i].times);
		}
	}
} 
int main()
{	
	FILE *fp1 = fopen("article.txt","r");
	Get(fp1);	 
	return 0;
}



