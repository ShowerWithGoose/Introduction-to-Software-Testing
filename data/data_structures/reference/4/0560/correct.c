#include<stdio.h>
#include<string.h>
struct f
{
	char a[100];
	int b;
	int flag;
} g[1000],v;
int main()
{
	FILE *fp=fopen("article.txt","r");
	int i=0,j=0,k,flag1=0,flag2=1;
	char q;
	for(i=0;i<1000;i++)
	{
		g[i].b=1;
		g[i].flag=0;
	}
	i=0;
	while((q=fgetc(fp))!=EOF)
	{
		
		if(q<'A'||(q>'Z'&&q<'a')||q>'z')
		{
			flag1=1;
		}
		else if((q<='z'&&q>='a')||(q<='Z'&&q>='A'))
		{
			if(flag1==1)
			{
				flag1=0;
				if(q<='Z'&&q>='A')
				q=q-'A'+'a';
				if(flag2==1)
				flag2=0;
				else
				i++;
				j=0;
				g[i].a[j++]=q;
			}
			else
			{
				if(q<='Z'&&q>='A')
				q=q-'A'+'a';
				g[i].a[j++]=q;
				flag2=0;
			}
		}
		
	}
	
	k=i;
	
	for(i=0;i<k+1;i++)
	{

		for(j=0;j<k;j++)
		if(strcmp(g[j].a,g[j+1].a)>0)
		{
			v=g[j];
			g[j]=g[j+1];
			g[j+1]=v;
		}
	}
	for(i=0;i<k+1;i++)
	{
		for(j=i+1;j<k+1;j++)
		{
			if(g[i].flag==0&&g[j].flag==0)
			if(strcmp(g[i].a,g[j].a)==0)
			{
				g[i].b++;
				g[j].flag=1;
			}
			
		}
	}
	for(i=0;i<k+1;i++)
	{
		if(g[i].flag==0)
		{
			printf("%s %d\n",g[i].a,g[i].b);
		}
		
		
	}
	return 0;
}

