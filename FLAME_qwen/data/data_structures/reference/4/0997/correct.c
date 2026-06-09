#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct word{
char wor[10005];
int count;
}a[10005];
int cmp(const void *p1,const void *p2)
{
	struct word *m=(struct word*) p1;
	struct word *n=(struct word*) p2;
	return strcmp(m->wor,n->wor);
}
int main()
{
	FILE* in;
	in=fopen("article.txt","r");
	int n=0,i;
	char s[100005];
	while(fgets(s,100005,in)!=NULL)
	{
		int l=strlen(s),k;
		char temp[100005];
		for(i=0;i<l;)
		{
			while(!isalpha(s[i])&&i<l)
			i++;
			int j=0;
			while(isalpha(s[i])&&i<l)
			{temp[j]=tolower(s[i]);j++;i++;}
			temp[j]='\0';
			int t=1;
			if(j>0)
			{
			for(k=0;k<n;k++)
			{
				if(!strcmp(a[k].wor,temp))
				{a[k].count++;t=0;break;}
			}
			if(t)
				{strcpy(a[n].wor,temp);a[n++].count=1;}
			}
		}
		
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
	{
		
		printf("%s %d\n",a[i].wor,a[i].count);
	}
	return 0;
}

