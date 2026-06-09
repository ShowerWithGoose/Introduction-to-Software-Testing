#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct article
{
	char a[100];
	int num;
};
int main(int argc,char *argv[])
{
	struct article art[1000];
	struct article z[1000];
	struct article ar;
	int i=0,j=0,k=0,l=0,m=0,n=0,p=0;
	char c[10000];
	FILE *in;
	in=fopen("article.txt","a+");
	while((c[i]=fgetc(in))!=EOF)
		i++;
	c[i]='\0';
	k=strlen(c);
	for(i=0;i<k;i++)
	{
		if(c[i]>='A'&&c[i]<='Z')
			c[i]=c[i]-'A'+'a';
		if(c[i]>='a'&&c[i]<='z')
		{
			art[n].a[m]=c[i];
			m++;
			l=1;
		}
		else
		{
			if(l==1)
			{
				n++;
				m=0;
				l=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(art[i].a,art[j].a)==0)
			{
				art[i].num++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(strcmp(art[i].a,art[j].a)<0)
			{
				ar=art[i];
				art[i]=art[j];
				art[j]=ar;
			}
			if(strcmp(art[i].a,art[j].a)==0)
			{
				if(art[j].num<art[i].num)
					art[j].num=art[i].num;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		l=0;
		for(j=0;j<i;j++)
		{
			if(strcmp(art[i].a,art[j].a)==0)
			{
				l=1;
			}
		}
		if(l==0)
		{
			z[p]=art[i];
			p++;
		}
	}
	for(i=0;i<p;i++)
		printf("%s %d\n",z[i].a,z[i].num+1);
	fclose(in);
	return 0;
}

