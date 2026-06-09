#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
int cmp( const void *p1, const void *p2 );
struct link{
	char v[50];
	int n;
}; 
struct link a[10000];
char b[50];
int main()
{
	freopen("article.txt","r",stdin);
	char c[1000];
	int i,l,t=0,r=0,j,panduan;
	while(gets(c)!=NULL){
	l=strlen(c);	
	for(i=0;i<l;i++)
	{
		if(tolower(c[i])>='a'&&tolower(c[i])<='z')
		{
			for(t=0;tolower(c[i])>='a'&&tolower(c[i])<='z';t++)
			{
				b[t]=tolower(c[i]);
				i++;
			}
			b[t]='\0';
			for(j=0,panduan=1;j<r;j++)
			{
				if(strcmp(a[j].v,b)==0)
				{
					a[j].n++;
					panduan=0;
					break;
				}
			}
			if(panduan)
			{
				a[j].n=1;
				strcpy(a[j].v,b);
				r++;
			}
			memset(b,'\0',sizeof(b));
		}			
	}
	}
	qsort(a,r,sizeof(a[0]),cmp);
	for(i=0;i<r;i++)
	{
		printf("%s %d\n",a[i].v,a[i].n);
	}
	return 0;
}
int cmp( const void *p1, const void *p2 )
{
	struct link*c=(struct link*)p1;
	struct link*d=(struct link*)p2;
	return strcmp(c->v,d->v);
}

