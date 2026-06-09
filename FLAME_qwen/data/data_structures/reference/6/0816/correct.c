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
#define MAXSIZE 100

int main()
{
	int op,num;
	int stack[MAXSIZE];
	int top=-1;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==1)
		{
			scanf("%d",&num);
			++top;
			if(top==MAXSIZE){
			printf("error ");
			top--;
		    }
			else
			stack[top]=num;
		}
		if(op==0)
		{
			--top;
			if(top<-1)
			{
				printf("error ");
				top++;
			}
			else
			printf("%d ",stack[top+1]);
		}
		if(op==-1)
		break;
	}
	return 0;
	
}




