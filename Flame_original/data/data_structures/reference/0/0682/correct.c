#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int f(char a,char b);//判断是否满足拓展条件 
int main()
{ 
 char s[1000];
 char *p=NULL,*pp=NULL;
 int i,j;
 gets(s);
 p=strchr(s,'-');//直接寻找 - 
 if(p==NULL)
 {
  puts(s);//没有就直接输出 
 }
 else
 {             //pp是用来定位p至末尾是否还有'-'   ***********注意如果'-'是结尾不要拓展 
  for(p=s;  (pp=strchr(p,'-'))!=NULL&&(pp+1)!=NULL;   )
  {
   if(f(*(pp-1),*(pp+1))==1)  //判断是否拓展 
   {
    for(i=0;i<pp-p;i++)
    {
     printf("%c",*(p+i));//输出拓展符前的内容 
    }
    for(i=1;i<=*(pp+1)-*(pp-1);i++)
    {
     printf("%c",*(pp-1)+i); //输出拓展符后的内容 
    }
   }
   else   //如果不满足条件
   {
    for(i=0;i<pp-p+2;i++)
    {
     printf("%c",*(p+i));
    }
   }
   p=pp+2;
  }
  for(i=0;i<strlen(s)-(p-s);i++)  //输出最后一个拓展符到结尾的内容 
  {
   printf("%c",*(p+i));
  }
 }
 return 0;
}
int f(char a,char b)
{
 if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&b-a>0) //均为小写字母且后面比前面大 
 {
  return 1;
 }
 else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&b-a>0) //均为大写字母且后面比前面大 
 {
  return 1;
 }
 else if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&b-a>0)//均为数字且后面比前面大 
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

