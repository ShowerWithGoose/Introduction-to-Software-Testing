#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
struct word{
	int cnt;
	char w[100];
}a[10000];
int cmp(const void *p,const void *q)
{
	char *aa=((struct word *)p)->w;
	char *b=((struct word *)q)->w;
	if(strcmp(aa,b)>0)return 1;
	else return -1;
}
int main()
{
	int i=0,j,k,flag,n,isword=0;
	char s,c[100];
	FILE *in;
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&s)!=EOF)
	{
		if(s=='\0')break;
		if(isword==0&&isalpha(s))
		{
			isword=1;
			memset(c,'\0',100);
			k=0;
			c[k]=tolower(s);
			k++;
			while(1)
			{
				fscanf(in,"%c",&s);
				if(!isalpha(s))
				{
					isword=0;
					break;
				}
				else{
					c[k]=tolower(s);
					k++;
				}
				
			}
			strcpy(a[i].w,c);
			a[i].cnt=1;
			i++;
		}
	}
	n=i;
	qsort(a,n,sizeof(struct word),cmp);
	for(i=1;i<n;i++)
	{
		if(strcmp(a[i-1].w,a[i].w)==0)
		{
			flag=1;
			a[i].cnt--;
			j=1;
			for(;strcmp(a[i-1].w,a[i+j].w)==0;j++)
			{
				flag++;
				a[i+j].cnt--;
			}
			a[i-1].cnt+=flag;
			i+=flag;
		}
	}
	for(i=0;i<n;i++)
	{
		if(strlen(a[i].w)&&a[i].cnt)
		printf("%s %d\n",a[i].w,a[i].cnt);
	}
	fclose(in);
	return 0;
}


