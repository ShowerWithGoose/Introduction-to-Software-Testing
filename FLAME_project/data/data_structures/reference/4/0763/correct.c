#include<stdio.h>
#include<math.h>
#include<string.h>
struct word{
	char w[100];
	int o;
};
struct word ab[100000];
struct word ex;
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	int x,y,m,n=0;
	char c;
	while(!feof(in))
	{
		fscanf(in,"%c",&c);
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		{
			for(x=0;(c>='a'&&c<='z')||(c>='A'&&c<='Z');x++)
			{
			ab[n].w[x]=c;
			fscanf(in,"%c",&c);
			}
			ab[n].o=1;
			n++;
		}
    }
	for(x=0;x<n;x++)
	{
		for(y=0;ab[x].w[y]!='\0';y++)
		if(ab[x].w[y]<97)
		ab[x].w[y]+=32;
	}
	for(x=0;x<n-1;x++)
	for(y=x+1;y<n;y++)
	{
		if(strcmp(ab[x].w,ab[y].w)>0)
		{
			ex=ab[x];
			ab[x]=ab[y];
			ab[y]=ex;
		}
		if(strcmp(ab[x].w,ab[y].w)==0)
		{
			ab[x].o++;
			if(y!=n-1)
			for(m=y;m<n-1;m++)
			ab[m]=ab[m+1];
			n--;
			y--;
		}
	}
	for(x=0;x<n;x++)
	{
		printf("%s %d\n",ab[x].w,ab[x].o);
	}
	fclose(in); 
	return 0;
}

