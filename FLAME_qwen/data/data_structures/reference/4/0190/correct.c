#include <stdio.h>
#include <ctype.h>
#include <string.h>
typedef struct Word{
 char s[20];
 int num;
} Word;   
int compare(struct Word *x,struct Word *y)
{
	return strcmp(x->s,y->s);
}        
int main()
{
 char ch;
 int wordStart=0,numberofword=0;   //numberofword单词总数
 Word word[200];       //可以存储不同单词以及其个数的"单词表"
 int i=0,j=0,k,m=0;    
 char copy[20]="";     //暂存读取的一个完整单词
 
 FILE *in=fopen("article.txt","r");   //只读方式打开文件;
 for(i=0;i<200;i++)
 {
   word[i].num=0;           //把结构体数组成员的num全部赋值为0
 } i=0;                    //i置为0 
 
 
 while(feof(in)==0)        //返回值为0表示未结束 
 {
  ch=fgetc(in);
  if(isalpha(ch)!=0)        //单词开始
  {
   wordStart=1;             //标记
   if(ch<='Z'&&ch>='A')
   {
   	 ch=tolower(ch);
   }
   copy[i++]=ch;            //把一个完整单词每个字符依次存进copy
  }
  else if(isalpha(ch)==0&&wordStart==1)  //判断一个单词结束
  {
   numberofword++;          //单词总个数+1
   wordStart=0;
   i=0;
   for(j=0;j<(m+1);j++)
   {
    if(strcmp(word[j].s,copy)==0)
    {
     k=0;                  //标志前面出现过
     word[j].num++;        //相同单词计数+1
     break;
    }
    else
     k=1;   
   }
 
   if(k==1)  //标志未出现过的新单词
   {
    for(j=0;j<20;j++)   //将新单词加入"单词表"
    {
     word[m].s[j]=copy[j];  
    }
    word[m].num++;
    m++;  //单词表成员个数＋1，同时也是下一成员的下标。
   }
   for(j=0;j<20;j++)  //一个单词结束，copy清空
   {
    copy[j]=NULL;
   }
  }
 }
 qsort(word,m,sizeof(Word),compare);  //字典序 
 //printf("不同的单词个数：%d\n",m);
 //printf("总单词个数：%d\n",numberofword);
 for (j=0;j<m;j++)
 {
  printf("%s",word[j].s);
  printf(" %d\n",word[j].num);
 }
 return 0;
}

  


		
 
	
	
		




