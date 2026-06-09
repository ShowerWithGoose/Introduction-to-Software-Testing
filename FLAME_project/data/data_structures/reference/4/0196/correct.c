#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 
struct node{
	char c[1024];
	int num;
}a[10002]; 
char tp[502],s[1000005];
int comp(char a[],char b[])
{
	int i;
	for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
	if(a[i]>b[i]) return 1;
	else if(a[i]<b[i]) return -1;
	if(a[i]=='\0'&&b[i]=='\0') return 0; 
	if(a[i]=='\0') return -1;
	return 1;
}
int cmp(const void *p1,const void *p2)
{
	struct node *a=(struct node *)p1;
	struct node *b=(struct node *)p2;
	return comp(a->c,b->c);
}
int main()
{
	freopen("article.txt","r",stdin);
	int n=0,i,j,fl;
	while(gets(s)!=NULL)
	{
		for(i=0;s[i]!='\0';i++)
		if(isalpha(s[i]))
		{
			j=0;fl=0;
			memset(tp,'\0',sizeof(tp));
			while(isalpha(s[i]))
			{
				if(isupper(s[i])) s[i]=tolower(s[i]);
				tp[j++]=s[i];
				i++;
			}i--;
			tp[j]='\0';
			for(j=1;j<=n;j++)
			if(strcmp(a[j].c,tp)==0) 
			{
			    fl=j;break; 
			}
			if(fl) a[fl].num++;
			else 
			{
				n++;
				memcpy(a[n].c,tp,sizeof(tp));
				a[n].num=1;
			}
		}
	}
	qsort(a+1,n,sizeof(struct node),cmp);
	for(i=1;i<=n;i++)
	printf("%s %d\n",a[i].c,a[i].num);
}



