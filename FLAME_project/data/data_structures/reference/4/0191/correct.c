#include <stdio.h>
#include <string.h>
struct word{
	char c[100];
	int b;
}wordd[100],x;
int main()
{
	FILE *fp,*pp;
	fp=fopen("article.txt","r");
	if(fp==NULL)
	{
		printf("Can't open the file!\n");
		return -1;
	}
	char temp,ch[1000];
	int i=0;
	for(i=0;i<998;i++)
	ch[i]=0;
	for(i=0;i<100;i++)
	{
		wordd[i].b=1;
	}
	i=0;
	temp=fgetc(fp);
	while(temp!= EOF)
	{
		ch[i]=temp;
		i++;
		temp=fgetc(fp);
	} 
	int k=0,j;
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]<='Z'&&ch[i]>='A')
		ch[i]=ch[i]+32;
	}
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]<='z'&&ch[i]>='a')
		{
			j=0;
			while(ch[i+j]<='z'&&ch[i+j]>='a')
			{
				wordd[k].c[j]=ch[i+j];
				
				j++;
			}
			k++;
			i=i+j;	
		}	
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-1-i;j++)
		{
			
			
			if(strcmp(wordd[j].c,wordd[j+1].c)>0)
			{
				x=wordd[j];
				wordd[j]=wordd[j+1];
				wordd[j+1]=x;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k+2;j++)
		{
			if(strcmp(wordd[i].c,wordd[j].c)==0)
			{
				wordd[i].b++;
				wordd[j].b=100000;
			}
			else if(strcmp(wordd[i].c,wordd[j].c)!=0)
			{
				i=j-1;
				break;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(wordd[i].b!=100000)
		{
			printf("%s %d",wordd[i].c,wordd[i].b);
			printf("\n");
		}
	}
	return 0;	
} 

