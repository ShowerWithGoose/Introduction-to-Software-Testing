#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[20000],c;
int i=0,m=0,j=0,n,flag;
struct list{
	char com[500];
	int num;
} stu[20000];
//去重 计数 
void del(struct list stu[])
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strlen(stu[i].com)==strlen(stu[j].com))
			{
				flag=strcmp(stu[i].com,stu[j].com);
			    if(flag==0)
					strcpy(stu[j].com,"*"),stu[i].num++;
			}
		}
	}
}
//排序
void sort(struct list stu[])
{
	char temp[50];
	int temp2;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(stu[i].com,stu[j].com)>0)
			{
				strcpy(temp,stu[i].com);
				strcpy(stu[i].com,stu[j].com);
				strcpy(stu[j].com,temp);
				temp2=stu[i].num;
				stu[i].num=stu[j].num;
				stu[j].num=temp2;
			}
		}
	}	
}
int main()
{
	//读+存数组 
	FILE *fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF)
		s[i++]=c;
		s[i]='\0';
	i=0;
	//切割+变小写 
	for(m=0;m<strlen(s);m++)
	{
		if(isalpha(s[m]))
		{
			stu[i].com[j]=s[m]|32;
			j++;
		}
		
		else
			i++,j=0;
	}
	n=i;		
	del(stu);
	sort(stu);
	
	for(i=0;i<n;i++)
	{
		if((stu[i].com[0]!='*')&&(stu[i].com[0]!='\0'))
	    	printf("%s %d\n", stu[i].com, stu[i].num+1);
	    //puts(stu[i].com); 
	}
	return 0;
}



