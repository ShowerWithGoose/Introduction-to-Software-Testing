//不变为0，两次qsort排序
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>//没这个就有错
int cmp(const void *p,const void *q);
struct file_WORD{
  char word[300];
  int count;//记录每个单词的出现了几次
};
struct file_WORD save[10000];
int main()
{
  int i=0,j=0,t=0;
  char c;
  FILE *in;
  int n,all;

  in=fopen("article.txt","r");
  if(in==NULL)
  {
    printf("Can't open the file.");
    return 1;
  }
  else
  {
    i=0,j=0;
    c=fgetc(in);//读入一个
    while(c!=EOF)//不断地从文件中读入字符//char对应EOF
    {
      j=0;
      if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
      {
        while((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
        {
          save[i].word[j]=tolower(c);
          j++;
          c=fgetc(in);//要有这句，不然死循环
        }
        save[i].count=1;
        i++;
      }
      c=fgetc(in);//接着读入 //变化
    }
  }//共有i个单词
  n=i;
  all=n;//开始共有all个词
  qsort(save,n,sizeof(struct file_WORD),cmp);
  
//   for(i=0;i<n;i++)
//   {
//     printf("%s %d\n",save[i].word,save[i].count);
//   }
// printf("**\n");

  //查找去掉重复的
  for(i=0;i<all;i++)//必须得是i<all【要所有内容都排查一遍】,如果是i<n就错了 
  {
    if(strcmp(save[i].word,save[i+1].word)==0)//有一个相同的
    {
      for(t=1;;t++)
      {
        if(strcmp(save[i].word,save[i+t].word)!=0)
        break;
        else
        save[i+t].word[0]='z'+1;//不能='0'，因为0的ascii值小于字母
      }
      save[i].count=save[i].count+(t-1);//有t-1个重复的
      i=i+t-1;//要接着比，没这句就错了
      n=n-(t-1);
      //想要用n-(t-1)，可以再用一个qsort排好序
    }
  }

  qsort(save,all,sizeof(struct file_WORD),cmp);
  for(i=0;i<n;i++)
  {
    printf("%s %d\n",save[i].word,save[i].count);
  }
  fclose(in);
  return 0;
}
int cmp(const void *p,const void *q)//按字典序升序排列
{
  struct file_WORD *a=(struct file_WORD *)p;
  struct file_WORD *b=(struct file_WORD *)q;
  if(strcmp(a->word,b->word)<=0)
  return -1;
  else
  return 1;
}
