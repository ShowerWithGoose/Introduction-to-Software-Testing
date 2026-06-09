#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void zhuanhuan(char a[])
{
	int i=0;
	for(;a[i]!='\0';i++)
	{
		if(a[i]<='Z'&&a[i]>='A')
		a[i]=a[i]-'A'+'a';
	}
}
struct d{
	char danc[1000];
};
int f(const void *a,const void *b)
{
	struct d *p1=(struct d *)a,*p2=(struct d *)b;
	return strcmp(p1->danc,p2->danc);
}
int main()
{
	FILE *in;
	int i=0,j=0,k=0,num=1;
	struct d g[2000];
	char gz[1000],cz[1000],*p;
	in=fopen("article.txt","r");
	if(in==NULL)
	printf("error");
	while(fgets(gz,1000,in)!=NULL)
	{
		zhuanhuan(gz);
		for(i=0;gz[i]!='\0';i++)
		{
			if((gz[i]<='z'&&gz[i]>='a'))
			{
				cz[j]=gz[i];
				j++;
			}
			else
			{
				cz[j]=' ';
				j++;
			}
		}
		cz[j]='\0';
		j=0;
		p=cz;
		while(sscanf(p,"%s",g[k].danc)!=EOF)
		{
			p=p+strlen(g[k].danc);
			while(*p==' ')
			{
			p++;	
			}
			k++;
		}
	}
	g[k].danc[0]='0';
	qsort(g,k,sizeof(struct d),f);
	for(i=0;i<k;i++)
	{
		if(strcmp(g[i].danc,g[i+1].danc)==0)
		{
			num++;
		}
		else
		{
		printf("%s %d\n",g[i].danc,num);
		num=1;
		if(i==k-1)
		{
			return 0;
		}
		}
	}
}



