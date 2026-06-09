#include<stdio.h>
#include<string.h>
#include <ctype.h>
struct jilu
{
	char a[100];
	int b;
};
int main()
{
	char c,s[10000];
	int count=0,l1,i,j=0,k=0;
	struct jilu info[1000];
	FILE *f;
	f=fopen("article.txt","r");
	c=fgetc(f);
	while(c!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			c=tolower(c);
		}
		s[count++]=c;
		c=fgetc(f);
	}
	l1=strlen(s);
	for(i=0;i<l1;i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			info[k].a[j++]=s[i];
		}
		if(((s[i-1]>='a'&&s[i-1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'))&&(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))))
		{
			k=k+1;
			j=0;			
		}
	}
	for(i=0;i<k;i++)
	{
		info[i].b=1;
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if((strcmp(info[i].a,info[j].a)==0)&&(info[j].b!=0)&&(info[i].b!=0))
			{
				info[i].b=info[i].b+1;
				info[j].b=0;
				j=i+1;
			}
		}
	}
	struct jilu tmp;
		for(i=0;i<k;i++)
	{
		for(j=i;j<k;j++)
		{
			if(strcmp(info[i].a,info[j].a)>0)
			{
				tmp=info[i];
				info[i]=info[j];
				info[j]=tmp;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(info[i].b!=0)
		{
			printf("%s %d\n",info[i].a,info[i].b);
		}
	}
	fclose(f);
	return 0;
}

