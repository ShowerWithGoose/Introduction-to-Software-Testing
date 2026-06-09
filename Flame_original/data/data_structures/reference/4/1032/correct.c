#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct total 
{
	char word[30];
	int num;
};

struct total ele[1000];

void bubble(int a);
void number(int a);


int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char ch;
	int i,j,flag=0;
	
	i=0;j=0;
	ch=fgetc(in);
	
	while(ch!=EOF)
	{
			
			while((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
			{
				if(ch>='A'&&ch<='Z')
					ele[i].word[j++]=ch+'a'-'A';
			
				else if(ch>='a'&&ch<='z')
					ele[i].word[j++]=ch;
				  
				ch=fgetc(in);
				flag=1;	
			}
		
		if(flag)
		{
			ele[i].word[j]='\0';
			ele[i].num=1;
			i++;	
			flag=0;
			j=0;
		}
	  ch=fgetc(in);	
			
	}//读入蛋词
		
	number(i);//统计个数 
	bubble(i);
	for(j=0;j<i;j++)
	{
		if(ele[j].num) 
		printf("%s %d\n",ele[j].word,ele[j].num);
	}
	
	return 0;
		 
}

void number(int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=i+1;j<a;j++)
		
		if((ele[j].num)&&strcmp(ele[i].word,ele[j].word)==0)
		{
			ele[i].num++;
			ele[j].num=0;
		}
	
}

void bubble(int a)
{
	int i,k;
    struct total tem;
	for(i=0;i<a-1;i++)
		for(k=0;k<a-1-i;k++)
		{
			if(strcmp(ele[k].word,ele[k+1].word)>0)
			{
				tem=ele[k];
				ele[k]=ele[k+1];
				ele[k+1]=tem;
			}
		}
}



