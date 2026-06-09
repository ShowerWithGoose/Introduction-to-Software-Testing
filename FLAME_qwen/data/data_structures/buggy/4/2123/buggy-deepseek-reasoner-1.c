/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int num[100];
    int i=0;
    int j=0;
    int k=0;
    int m=0;
    int n=0;
    char c=0;
    char word[1000][100]={};
    char flag[100]={};
    FILE *in;
    in=fopen("article.txt","r");
    c=fgetc(in);
    while(c!=EOF)
      {
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ 错误：条件使用了&&，应该为||，且应包含等号（>='a'等），导致永远无法识别字母
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ 错误：分隔符识别不完整，应使用!isalpha(c)判断非字母字符，否则无法处理换行符、标点等
        {    
              word[i][j]='\0';
              j=0;
              i+=1; // @@ 错误：未检查j>0，如果连续多个分隔符会导致产生空单词条目
              n+=1; // @@ 错误：同上，n计数不应在无单词时增加
    }
    c=fgetc(in);
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++) // @@ 错误：循环条件应为j<strlen(word[i])，即按单词实际长度处理，此处会导致越界访问其他单词
        {
              word[i][j]=tolower(word[i][j]);
        }
      }
      for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
        {
              if(strcmp(word[i],word[j])>0)
              {
                strcpy(flag,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],flag);
              }
        }
      }    
      for(i=0;i<n;i++)
      {
        if(strlen(word[i])>0)
          { 
               for(j=i+1;j<n;j++)
               {
                 if(strcmp(word[i],word[j])==0)
                 {
                       num[i]++; // @@ 错误：num数组未初始化为0，此处自增基于不确定的初值
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ 错误：num[i]未初始化，+1后结果不可预期
      }
      fclose(in);
      return 0; 
}