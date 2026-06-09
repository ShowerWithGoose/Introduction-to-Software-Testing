#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct word
{
	char w[50];//存单词 
	int f;//存出现频数 
}num[500],nums;
void order(struct word num[500],struct word nums,int k);//排序 
int main()
{
	FILE *in;
	in = fopen("article.txt","r");
	int i=0,l;
	char c,a[1200];
	while((c=fgetc(in))!=EOF)//读入文件，将文件中字母全部变为小写并存储在数组a中 
	{
		if(c>='A'&&c<='Z')
			a[i]=c+'a'-'A';//大写变小写 
		else
			a[i]=c;//小写和空格照常 
		i=i+1;
	}
//	puts(a);
	
	/*for(i=0;(c=fgetc(in))!=EOF;i++)//存储每一个字符 
		a[i]=c;//把文件中字符存到a数组中 
	a[i]='\0';
	l=strlen(a);//文件长度 
	int k=0,j=0;
	for(i=0;i<l;i++)
	{
	
	}*/

	int k=0,j=0;
	l=strlen(a);
	for(i=0;i<l;i++)
	{	
		if(a[i]>='a'&&a[i]<='z')//小写字母 
		{
			num[k].w[j]=a[i];//单词存入结构体num.w中 
			j=j+1;
			num[k].f=1;//词频设为1
		}
		else//遇空格 
		{
			k=k+1;//下一个单词 
			j=0;
		}
	}
	for(i=0;i<k;i++)//k为总单词数 
	{
		for(j=i+1;j<k;j++)
		{
			if(num[i].w[0]!='\0')
			{
				if(strcmp(num[i].w,num[j].w)==0)//单词相同 
	    		{
	    			num[i].f=num[i].f+1;//词频加1 
	    			num[j].w[0]='\0';//相同单词标记以便去除 
	    		}
			}
		}
	}
	order(num,nums,k);//排序 
	for(i=0;i<k;i++)
	{
		if(num[i].w[0]!='\0')
			printf("%s %d\n",num[i].w,num[i].f);//输出单词及频数 
	}
	fclose(in);
	return 0;
}

void order(struct word num[500],struct word nums,int k)
{
	int i,j;
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(strcmp(num[i].w,num[j].w)>0&&num[i].w[0]!='\0')//排序
			{
				nums=num[i];
				num[i]=num[j];
				num[j]=nums;	
			}
		}
	}
}





