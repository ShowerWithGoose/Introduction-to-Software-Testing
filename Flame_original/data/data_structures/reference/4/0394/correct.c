#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b){
    char *a1 = (char *) a;
    char *b1 = (char *) b;
    return strcmp(a1,b1);
}

int main ()
{
	FILE * f1;
	f1=fopen("article.txt","r");
	char s[1000][20];
	int ch;
	char s0[100][100];
	int i,j,k;
	i=0;
	while(fgets(s0[i],1000,f1)!=NULL)
	{
		i++;
	 } 
	int line;
	line=i; 
//	printf("%d\n",line);
	for(i=0;i<line;i++)
	{
		int len =strlen(s0[i]);
		for(j=0;j<len;j++)
		{
			if(s0[i][j]>=65&&s0[i][j]<=90)
			s0[i][j]+=32;
		}
	}
	int m,n;
	m=0;n=0;
	for(i=0;i<line;i++)
	{
		int len ;
		len=strlen(s0[i]);
		for(j=0;j<len;j++)
		{
			if(s0[i][j]>=97&&s0[i][j]<=122)
			{
				n=0;
				for(;s0[i][j]>=97&&s0[i][j]<=122;j++)
				{
					s[m][n]=s0[i][j];
					n++;
				}
				s[m][n]='\0';
				m++;
			}
		}
	}
	int num=m;
//	for(i=0;i<m;i++)
//	printf("%s\n",s[i]);
	qsort(s,num,sizeof(s[0]),cmp);
//	for(i=0;i<m;i++)
//	printf("%s\n",s[i]);
	int p;
	int b[500]={0};
	for(i=0;i<500;i++)
	b[i]=1;
	for(i=0;i<num;i++)
	{
		if(cmp(s[i],s[i+1])==0)
		{
			p=i;
			b[p]=1;
			for(;strcmp(s[i],s[i+1])==0;i++)
			{
				b[p]+=1;
				b[i+1]=-1;
			}
			
		}
	}
	for(i=0;i<num;i++)
	{
		if(b[i]>0)
		printf("%s %d\n",s[i],b[i]);
	}
	
	return 0;
}

