#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#include <ctype.h>
#define eps 1e-8
#define pi 3.14
struct node
{
	char name[50];
	int num;
};
int rise_double(const void *p1, const void *p2);
int main()
{	
	struct node a[10000]={};
	char c;char word[500];
	int i,j=0,k;int flag=1,flag2;
	FILE *in;
	in=fopen("article.txt","r");
	
	for(i=0;i<10000;i++)
	a[i].num=1;//所有的数量赋值为1 
	
	i=0,j=0;//i是单词的种类数 ，在循环之前有0种 
	while((c=fgetc(in))!=EOF)
	{	
	//	c=fgetc(in);
		if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
		{
			if(c<='Z'&&c>='A')
			c=tolower(c);
			word[j]=c;j++;flag=0;}
			
		else if(!((c<='z'&&c>='a')||(c<='Z'&&c>='A'))&&flag==0)
		{
			j=0;//下一次从word【0】开始赋值 
			flag=1;
			flag2=1;
			for(k=0;k<=i-1;k++)// 
			{
				if(strcmp(word,a[k].name)==0)
				{
					a[k].num++;memset(word,'\0',500);flag2=0;
				}
			}
			if(flag2==1)
			{	
				strcpy(a[i].name,word);	
				i++;
				memset(word,'\0',500);}
		}
	}
		qsort(a,i,sizeof(a[1]),rise_double);
	for(j=0;j<i;j++)
	{
	printf("%s %d\n",a[j].name ,a[j].num);
	}
}
	
int rise_double(const void *p1, const void *p2) 
 {
 	struct node *c=(struct node*)p1;
 	struct node *b=(struct node*)p2;
 	return strcmp(c->name,b->name);
 	}
	

	



