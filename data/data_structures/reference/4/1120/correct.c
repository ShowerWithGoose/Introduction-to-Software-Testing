#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 500
//模块化处理 :（先将所有的字母转为小写）1.读取单词（全部为小写）2.排序3.去重4.输出
//参考博客// 
//或许使用数组 
struct node{
	char word[N];
	int cnt;
	//在读入单词时记得初始化为一 
};
typedef struct node Node;
int num=0;//此时结构体数组最大下标（个数-1） 
char ch;
void ctl(FILE *);//将所有的字母转化为小写 
void getword();//将单词提取出来并放入数组中
int cmp3(const void *p1, const void *p2)
{
    struct node *x = (struct node *)p1;
    struct node *y = (struct node *)p2;
    int cmp=strcmp(x->word,y->word);
    return cmp;
};//结构体排序  
int ii;
char xx[2022];//转化为小写字母后的一行字符串 
Node a[N];//结构体数组 

int main()
{	
    FILE *in;
    in=fopen("article.txt","r");
	int j,k;
	//将单词提取出来 ：第一个字母字符直到第一个不为字母的字符 
	ctl(in);
	//printf("%s",xx);
	//printf("%d\n",ii);	
   	getword();
	qsort(a,num,sizeof(Node),cmp3);
	
	//去重
	for(j=0;j<=num;j++)
	{
		if(strcmp(a[j].word,a[j+1].word)==0)
		{
			a[j+1].cnt+=a[j].cnt;
			a[j].cnt=0;
		}
	}
	for(j=0;j<=num;j++)
	{
		if(a[j].cnt!=0)
		printf("%s %d\n",a[j].word,a[j].cnt);
	 } 
	fclose(in); 
} 



void ctl(FILE *in) //转化为小写 
{
	while((ch=fgetc(in))!=EOF)
	{
		if(isalpha(ch))
		{
			xx[ii++]=tolower(ch);
		}
		else
		xx[ii++]=ch;
	}
}

void getword()
{
	int i,m;
	for(m=0;m<ii;m++)
	{
		if(isalpha(xx[m]))
		{
			for(i=0;isalpha(xx[m+i])!=0;i++)
				a[num].word[i]=xx[m+i];
			m+=i;
			a[num].word[i]='\0';
			a[num].cnt=1;			
			num++;
		}
    }
}




