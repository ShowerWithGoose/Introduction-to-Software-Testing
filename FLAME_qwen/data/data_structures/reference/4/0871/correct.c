#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Article{
	char words[15];//单词数
	int num;//单词出现次数
}book[1024];//结构体数组，结构体指针
struct Article* p;
char str[1005];
char b[1009][19];//二维数组存放每行单词
char temp[19];//空数组用于转换
FILE*in;//只读文件指针
int x=0;//单词数
void Delete(struct Article book[]);//删除函数
void sort(struct Article book[]);//排序结构体数组
int main()
{
	int i,j,m,n;
	int sign=0;
	int s=0;
	if((in=fopen("article.txt","r"))==NULL)//打开文件失败，关闭
{
	exit (0); 
}
	while(fgets(str,1005,in)!=NULL)//如果文件仍未结束
	{
		//读入一个字符串（读取换行符后停止本次读入，等待while循环读第二行）
		sign=0;//标志符=0
		m=strlen(str);//测量字符长度（不包括换行）
		for(i=0;i<m;i++)
		{
			if(str[i]<=64||str[i]>=123||(str[i]>=91&&str[i]<=96))//如果不是字母或空格，跳过，标志键加1
			{
				sign++;
			}
			else
			{
				if(str[i]>=65&&str[i]<=90)
				{
					str[i]+=32;//字符是大写字母，转成小写字符
				}
				if(str[i+1]<65||(str[i+1]>90&&str[i+1]<97)||str[i+1]>122)//如果不是字母，单词结束
				{
					for(j=0;j<=s;j++,sign++)
					b[x][j]=str[sign];//单词复制到空的数组b中
					strcpy(book[x].words,b[x]);//再复制到结构体数组中
					x++;s=0;//清空单词长度数
				}
				if((str[i+1]>=65&&str[i+1]<=90)||(str[i+1]>=97&&str[i+1]<=122))
				{
					s++;//统计单词长度
				}
			}
		}
	}
	sort(book);
	Delete(book);
	for(i=0;i<x;i++)
	{
		if(strcmp(book[i].words,"0")!=0)
		printf("%s %d\n",book[i].words,book[i].num);
	}
	fclose(in);
	return 0;	
} 
void Delete(struct Article book[])
{
	int i,j,w,n=1;
	for(i=0;i<x;i++)
	{
		if(strcmp(book[i].words,book[i+1].words)==0)
		{
			strcpy(book[i].words,"0");
			n++;
			book[i].num=n;
		}
		else 
		{
			book[i].num=n;
			n=1;
			book[i+1].num=n; 
		}
	}
}
void sort(struct Article book[])
{
	int i,k;
	for(i=0;i<x-1;i++)
	{
		for(k=0;k<x-1;k++)
		{
			if(strcmp(book[k].words,book[k+1].words)>0)
			{
				strcpy(temp,book[k].words);
				strcpy(book[k].words,book[k+1].words);
				strcpy(book[k+1].words,temp);
			}
		}
	}
}





