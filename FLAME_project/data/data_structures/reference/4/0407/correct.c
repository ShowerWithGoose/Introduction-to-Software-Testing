#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct word{
	char s[100];
	int count; 
};
struct word a[500];

int cmp(const void *p1,const void *p2)
{
	struct word *a=(struct word*)p1;
	struct word *b=(struct word*)p2;
	return strcmp((*a).s,(*b).s);
}

int main()
{
	char c;
	char s1[1000];
	int i=0,j,k,n=0,l;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		s1[i]=c;
		if(s1[i]>='A'&&s1[i]<='Z') s1[i]=tolower(s1[i]);
		i++;
	}
	l=strlen(s1);
	
	for(i=0;i<l;i++)
	{
		if(s1[i]>='a'&&s1[i]<='z')
		{
			for(j=i;j<l;j++)
			{
				if(s1[j]<'a'||s1[j]>'z') break;
			}
			for(k=0;k<j-i;k++)
			{
				a[n].s[k]=s1[i+k];
			}
			a[n].s[k+1]='\0';
			a[n].count=1;
			n++;
			i=j;
		}
		
	}
	
	qsort(a,n,sizeof(struct word),cmp);
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].s,a[i+1].s)==0)
		{
			a[i+1].count+=a[i].count;
			memset(a[i].s,0,100*sizeof(char));
			a[i].count=0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i].count>0) printf("%s %d\n",a[i].s,a[i].count);
	}
	
	fclose(in);
	return 0;
}

