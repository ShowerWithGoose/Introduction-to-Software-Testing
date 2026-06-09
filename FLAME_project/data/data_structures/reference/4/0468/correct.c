#include <stdio.h>
#include <string.h>
#define MAX 101
char a[MAX][MAX];
char b[MAX]={0};
char c[MAX][MAX];
char d[MAX][MAX];
int num[MAX];
int main()
{
	FILE *in;
	int n=0,m=0,i,len,j,p=0,q;
	in=fopen("article.txt","r");
	while(fgets(b,sizeof(b),in)!=NULL)
	{
		strcpy(a[n],b);
		n++;
    }
	for(i=0;i<n;i++)
	{
		q=0;
		len=strlen(a[i]);
		for(j=0;j<len;j++)
		{
			if((a[i][j]>='a'&&a[i][j]<='z')||(a[i][j]>='A'&&a[i][j]<='Z'))
			{
				c[p][q]=a[i][j];
				q++;
			}
			else
			{
				p++;
				q=0;
			}
		}
	}
	for(i=0;i<p;i++)
	{
		len=strlen(c[i]);
		for(j=0;j<len;j++)
		{
			if(c[i][j]>='A'&&c[i][j]<='Z')
			c[i][j]=c[i][j]-'A'+'a';
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<p-i-1;j++)
		{
			if(strcmp(c[j],c[j+1])>0)
			{
				char str[MAX];
				strcpy(str,c[j]);
				strcpy(c[j],c[j+1]);
				strcpy(c[j+1],str);
			}
		}
	}
	for(i=0;i<MAX;i++)
	num[i]=1;
	for(i=0;i<p;i++)
	{
		if(strcmp(c[i],c[i+1])!=0)
		{
			strcpy(d[m],c[i]);
			m++;
		}
		else num[m]++;
	}
	for(i=1;i<m;i++)
	{
		printf("%s %d\n",d[i],num[i]);
	}
	fclose(in);
	return 0;
}


