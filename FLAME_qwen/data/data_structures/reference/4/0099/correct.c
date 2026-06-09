#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a;
char s[101],oo[10];
int num,o;
struct node
{
	int sum;
	char str[101];
}p[100100];
int cmp(const void *a1,const void *b1)
{
	struct node aa=*(struct node*)a1;
	struct node bb=*(struct node*)b1;
	return strcmp(aa.str,bb.str);
}
int main()
{
	s[0]='\0';oo[0]='\0';
	freopen("article.txt","r",stdin);
	while((a=getchar())!=EOF)
		{
			if((a<='z'&&a>='a')||(a<='Z'&&a>='A'))
				{
					if(a<='Z'&&a>='A')a-=('A'-'a');
					s[o++]=a;
				}
			else
			{
				s[o]='\0';
				if(s[0])
				{
					strcpy(p[++num].str,s);
					p[num].sum=1;
				}o=0;
				strcpy(s,oo);
			}
		}
	qsort(p+1,num,sizeof(p[0]),cmp);
	int i,j;
	for(i=1;i<=num;i++)
		{
			if(!strcmp(p[i].str,p[i-1].str))
				p[i].sum+=p[i-1].sum;
			if(strcmp(p[i].str,p[i+1].str))
				printf("%s %d\n",p[i].str,p[i].sum);
		}
}

