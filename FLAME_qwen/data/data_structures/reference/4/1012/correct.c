#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAXLINE 1024
int sp(char *a,char *b)
{
	int i=0,j=0;
	while(a[i]!=' ')
	{
		if(a[i]<b[j])return -1;
		else if(a[i]>b[j])return 1;
		else if(a[i++]==b[j++])continue;
	}
	return 0;
}
struct node{
	char word[1024];
	int num;
}dcb[1024];
struct node1{
	char word[1024];
	int num;
}paixu[1024];
int main()
{
	int i=0,j=0,k=0;//i计数line j计数store k计数dcb t1计数从0到k 
	char line[1024];//存每一行句子
	char store[1024];//存每一个单词 
	memset(store,'\0',1024);
	memset(line,'\0',1024);
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(line,1024,in)!=NULL)
	{
		i=0;
		while(line[i]!='\n')
		{
			while((line[i]<'A'||(line[i]>'Z'&&line[i]<'a')||line[i]>'z')&&line[i]!='\n')
			{
				i++;
			}
			while((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<'Z'))
			{
				if(line[i]>='A'&&line[i]<='Z')store[j]=line[i]+32;
				else store[j]=line[i];
				j++;
				i++;
			}
			int t1=0,rcd=0;
			while(dcb[t1].word[0]!='\0')
			{
				if(strcmp(dcb[t1].word,store)==0)
				{
					dcb[t1].num++;
					rcd=1;
					memset(store,'\0',1024);
					j=0;
				}
				else t1++;
			} 
			if(rcd==0&&store[0]!='\0')
			{
				memset(dcb[k].word,'\0',1024);
				strcpy(dcb[k].word,store);
				dcb[k].num++;
				k++;
				memset(store,'\0',1024);
				j=0;
			}
		 } 
	}//存完了 接下来排序
	int i2=0,i3=0,ltnum=0;
	int t1=1;
	char little[1024];
	memset(little,'\0',1024);
	while(dcb[i2].word[0]!='\0')
	{
		int rcd=i2;//记录每次最小的字符串的序号 
		char little[1001];
		if(dcb[i2].word[0]=='z'&&dcb[i2].word[1]=='z')i2++;
		else
		{
			ltnum=dcb[i2].num;
			strcpy(little,dcb[i2].word);
		while(dcb[i2+t1].word[0]!='\0')
		{
			if(sp(little,dcb[i2+t1].word)<=0)
			{
				strcpy(little,little);
				ltnum=ltnum;
				t1++;
				rcd=rcd;
				
			}
			else
			{
				strcpy(little,dcb[i2+t1].word);
				ltnum=dcb[i2+t1].num;
				rcd=i2+t1;
				t1++;
			}
		}
		strcpy(paixu[i3].word,little);
		paixu[i3].num=ltnum;
		memset(dcb[rcd].word,'z',sizeof(dcb[rcd].word));
		i3++; 
		t1=1;
		}
	} 
	for(i=0;dcb[i].word[0]!='\0';i++)
	{
		printf("%s ",paixu[i].word);
		printf("%d",paixu[i].num);
		printf("\n");
	}
	return 0;
} 

