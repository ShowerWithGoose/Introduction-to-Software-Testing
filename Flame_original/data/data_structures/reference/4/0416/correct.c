#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node{
	char s[1000];
	int num;	//记录每个单词出现次数 
}m[20000]; 		//	第几个单词 

int cmp(const void *a,const void *b)
{
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	return strcmp(c->s,d->s);
}
int main()
{
	FILE *fp=fopen("article.txt","r");
	char str[200000];
	char c;
	int k=0;
	while((c=fgetc(fp))!=EOF)		//读入文本字符 
	{
		str[k++]=c;
	}
	
	k=0;
	int i=0;
	int weishu=0;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(!isalpha(str[i]))		//如果不是字母，说明是空格或者符号 
		{
			k++;		//增加单词个数，反映第几个单词 
			weishu=0;		//刷新，马上开始记录另一个单词，反映单词位数 
		}
		
		else if(isalpha(str[i]))
		{
			m[k].s[weishu++] = tolower(str[i]);		//变成小写 
		}
	}
	
	qsort(m,k,sizeof(m[0]),cmp);
	
	for(i=0;i<k;i++)
	{
		if(strlen(m[i].s)!=0)		//先给所有是单词的标上 
			m[i].num=1; 
	} 
	
	for(i=0;i<k;i++)
	{
		if(strcmp(m[i].s,m[i+1].s)==0)		//是同一个词
		{
			m[i+1].num+=m[i].num;
			m[i].num=0;
		} 
	}
	
	for(i=0;i<k;i++)
	{
		if(m[i].num!=0)
		{
			printf("%s %d\n",m[i].s,m[i].num);
		}
	}
	
	return 0; 

	fclose(fp);	
}

