#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
//int strlen(char s[]);   	    /*计算字符串长度, 字符串以\0结果*/
//char *strcpy(char s[], char t[]); /*将字符串t拷贝到字符串s中*/
//char *strcat(char s[], char t[]); /*将字符串t拷贝到字符串s尾部*/
//int strcmp(char s[], char t[]);   /*比较两个字符串,若s>t,则返回大于0的数;若s<t,则返回小于0的数;若相等, 返回0 */
//int   atoi(char  s[ ]); 	/* 将字符串转换成相应整数 */
//getchar()/putchar(c) 		/*按字符输入输出 */

//gets(char s[])		/*输入由回车结束的串，回车本身不读入*/
//puts(char s[])		/*输出由‘\0’结束的串，自动加回车*/
//int  isalpha(int c)	是否是字母
//int  isdigit(int c)		是否是数字
//int  islower(int c)	是否是小写字母
//int  isupper(int c)	是否是大写字母
//int  isspace(int c)	是否是空白字符
//int  tolower(int c)	将大写字母为小写字母
//int  toupper(int c)	将小写字母为大写字母
//void * malloc ( size_t  size ) 申请动态空间用于初始化指针变量
#define MAXSIZE 1024
#define MAXLINE 50
#define MAXLIST 1000
struct node{
	char fword[MAXLINE];
	int count;
	
};
struct node wordlist[MAXLIST];
int cmp(const void*_a,const void*_b)
{
	struct node*a=(struct node*)_a;
	struct node*b=(struct node*)_b;
	return strcmp(a->fword,b->fword);
 } 
int main()
{
	int i,j,k,m;
	FILE*in;
	char line[MAXSIZE];
	if((in=fopen("article.txt","r"))==NULL)
	{
		printf("can't open the file");
		return -1;
	}
	j=0;
//	gets(line);
	while(fgets(line,MAXSIZE-1,in)!=NULL)
	{
	    for(i=0,k=0;i<=strlen(line);i++)
	    {
	    	if(isalpha(line[i]))
	    	{
	    		wordlist[j].fword [k]=tolower(line[i]);
	    		k++;
			}
			else if(i!=0&&!isalpha(line[i]))
			{
				wordlist[j].fword [k]='\0';
				j++;
				k=0;
				if(line[i]=='\0')
				break;
			}
			
		}

	}
	for(i=0;i<j;i++)
	{
		wordlist[i].count =1;
	}
	for(i=0;i<j;i++)
	{
		for(k=i+1;k<j;k++)
		{
			if(strcmp(wordlist[i].fword ,wordlist[k].fword )==0)
			{
				wordlist[i].count++;
				for(m=k;m<j;m++)
				{
					strcpy(wordlist[m].fword ,wordlist[m+1].fword ); 
					wordlist[m].count =wordlist[m+1].count ;
				}
				j--;
				k--;
			}
		}
	}
	qsort(wordlist,j,sizeof(struct node),cmp);
	for(i=1;i<j;i++)
	{
		for(k=0;k<(strlen(wordlist[i].fword ));k++)
		{
			printf("%c",wordlist[i].fword[k]);
		}
		printf(" ");
		printf("%d\n",wordlist[i].count );
	}
	fclose(in);
	return 0;
}



