#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	char word[100];
	int num;
};
int o=0;
char cha(char );
int rem(struct node list[]);
void sort(struct node list[]);
void plus(struct node list[]);
int main()
{
	int i=0;
	int k;
	int m;
	char c;
	int count=0;
	char w[300]={0};
	int j;
	struct node pha[100];
	char word1[300]={0};
	FILE*in;
	in=fopen("article.txt","r");
    while((c=fgetc(in))!=EOF)
    {
    	word1[i]=c;
        if(isalpha(word1[i])!=0)
        {
        	word1[i]=cha(word1[i]);
		}
    	i++;
	}
	for(i=0;i<strlen(word1);i++)
	{
		if(isalpha(word1[i])!=0)
		{
			for(j=i;j<strlen(word1);j++)
			{
				if(isalpha(word1[j])==0)
				{
					break;
				}
			}
		memset(w,0,sizeof(w));
		for(k=0;k<j-i;k++)
		{
		  w[k]=word1[i+k];	
		}
		strcpy(pha[o].word,w);
		o=o+1;
		i=j;
	}
	}
	for(i=0;i<o;i++)
	{
		pha[i].num=1;
	}
	while(1)
	{
		count=rem(pha);
		if(count==0)
		{
			break;
		}
		else
		{
			plus(pha);
		}
	}
    sort(pha);
    for(i=0;i<o;i++)
    {
    	printf("%s %d\n",pha[i].word,pha[i].num);
	}
	return 0;
}

void plus(struct node list[])
{
	int i;
	int j;
	int k;
    for(i=0;i<o;i++)
    {
    	for(j=i+1;j<o;j++)
    	{
    		if(strcmp(list[i].word,list[j].word)==0)
    		{
    			list[i].num=list[i].num+list[j].num;
    			for(k=j+1;k<o;k++)
    			{
    				list[k-1]=list[k];
				}
				o--;
			}
		}
    }
}
void sort(struct node list[])
{
	int i;
	int j;
	struct node temp;
	for(i=0;i<o;i++)
	{
		for(j=i+1;j<o;j++)
		{
			if(strcmp(list[i].word,list[j].word)>0)
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
	}
}
char cha(char b)
{
	if(b>='A'&&b<='Z')
	{
		b=b+32;
	}
	return b;
}
int rem(struct node list[])
{
	int i,j,k;
	int m=0;
	for(i=0;i<o;i++)
	{
		for(j=i+1;j<o;j++)
		{
			if(strcmp(list[i].word,list[j].word)==0)
			{
				m++;
			}
		}
	}
	return m;
}



