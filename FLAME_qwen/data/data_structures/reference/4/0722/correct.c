#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct collect
	{
		char word[1000];
		int number;
	};
	struct collect a[1000],hold;
	char ori[1000];
int main ()
{
	int i=0,j=0,k=0,n=0,t=0,m=0;
	FILE *in;
	in=fopen ("article.txt","r");
	if (in==NULL)
	{
		printf("fail\n");
		exit(0); 
	}
	for (i=0;fscanf(in," %s ",ori)!=EOF;)//输入 
	{
		
		for (k=0;ori[k]!='\0';)
		{
			while ((isalpha(ori[k]))==0&&ori[k]!='\0')//找到第一个字母 
			{
				k++;
			}
		
			for(j=0;(isalpha(ori[k]))!=0&&ori[k]!='\0';j++,k++)
			{
				a[i].word[j]=tolower(ori[k]);
			}
			a[i].word[j]='\0';
			a[i].number=1;
			i++;
				
		}
	
	}
	n=i;

	for (i=0;i<n;i++)//查找是否出现 
	{
	
		for (j=0;j<i;j++)
		{
			if (strcmp(a[j].word,a[i].word)==0)//出现过 
			{
				a[j].number++;
				a[i].number=0;
				break;
			}
			
		}
	}
	n=i;
		for(i=0;i<n-1;i++)//排序 
	{
		for(j=0;j<n-1-i;j++)
		{
			
			for (k=0;a[j].word[k]==a[j+1].word[k];k++)
			{
				
			}//找到第一个不同位 
			if (a[j].word[k]>a[j+1].word[k])
			{
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
			}
		}
	 } 
	 for (i=0;i<n;i++)
	 {
	 	if (a[i].number!=0&&a[i].word[0]!=NULL)
	 	{
	 		printf("%s %d\n",a[i].word,a[i].number);
		 }
	 }
	 return 0;
 } 

