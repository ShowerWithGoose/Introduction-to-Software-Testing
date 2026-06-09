#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h>

struct Node//查询单元 
{
	char s[50];//存单词 
	int n;//存次数 
}node[1024];

int cmp(const void*a,const void*b)//qsort的比较函数 
{
	struct Node*c=(struct Node*)a;
	struct Node*d=(struct Node*)b;
	return strcmp(c->s,d->s);
} 

int cha(char*s,int n)//查询在已有数组的前n项中中是否存在
{
	if(n==0) return -1;//无数据，不存在 
	for(int i=1;i<=n;i++)
	{
		if(strcmp(s,node[i].s)==0)
		{
			return i;//存在且在第i项的位置 
		}
	}
	return -1;//查询不到，不存在 
}

int main()
{
	FILE *in=fopen("article.txt","r");
	char ss[50];
	char s;
	int f=0,step=0;
	int c=0;//c为目前单元数组的末位，单元数组从 1开始 
	while((s=fgetc(in))!=EOF)//读入字符串 
	{
		if(isalpha(s) && f==0)
		{
			f=1;
		}
		if(isalpha(s) && f==1)
		{
			ss[step++]=s;
		}
		if(!isalpha(s) && f==1)
		{
			f=3;
			ss[step]='\0';
		}
		if(f==3)
		{
			for(int i=0;i<step;i++)//大小写转换 
			{
				if(ss[i]>='A' && ss[i]<='Z') ss[i]=ss[i]+'a'-'A';
			}
			if(cha(ss,c)==-1)//查询在已有数组中是否存在，若不存在
			{
				node[++c].n++;  
				strcpy(node[c].s,ss);
			}
			else//若存在 
			{
				node[cha(ss,c)].n++;
			}
			f=0;
			step=0;
		}
	}
	qsort(node,c+1,sizeof(struct Node),cmp);//qsort 
	for(int i=1;i<=c;i++)//输出 
	{
		printf("%s %d\n",node[i].s,node[i].n);
	}
	fclose(in);
	return 0; 
}

