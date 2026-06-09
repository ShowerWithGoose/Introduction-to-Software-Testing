#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct a{
	int b;
	char c[200];
};
int main()
{
	FILE *in;
	int n=0,i=0,j=0;
	int t=0,m;
	char e,f[200];
	struct a k[10000],k1;
	in=fopen("article.txt","r");
	while((e=fgetc(in))!=EOF)
	{
		if(e>='A'&&e<='Z')
		{
			e=e-'A'+'a';
			f[i]=e;
			i=i+1;
		}
		else if(e>='a'&&e<='z')
		{
			f[i]=e;
			i=i+1;
		}
		else if(f[0]!='\0')
		{
			for(j=0;j<n;j=j+1)
			{
				if(strcmp(f,k[j].c)==0)
				{
					k[j].b=k[j].b+1;
					t=1;
					break;
				}
				else
				t=0;
			}
			if(t==0)
			{
				strcpy(k[j].c,f);
				k[j].b=1;
				n=n+1;
			}
			i=0;
			for(m=0;m<100;m=m+1)
			f[m]='\0';
		}
	}
	for(i=0;i<n;i=i+1)
	{
		for(j=i+1;j<n;j=j+1)
		{
			if(strcmp(k[i].c,k[j].c)>0)
			{
				k1=k[i];
				k[i]=k[j];
				k[j]=k1;
			}
		}
	}
	for(i=0;i<n;i=i+1)
	{
		printf("%s %d\n",k[i].c,k[i].b);
	}
	return 0;
}

