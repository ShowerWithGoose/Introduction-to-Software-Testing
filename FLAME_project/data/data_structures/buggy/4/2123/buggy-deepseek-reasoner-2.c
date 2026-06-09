/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int num[100]; // @@ 未初始化为0，导致后续计数基于垃圾值
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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ 条件错误，应使用||且包含等于，无法正确识别字母
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ 分隔符不完整，未包含标点、换行符等非字母字符
        {    
              word[i][j]='\0';
              j=0;
              i+=1;
              n+=1; // @@ 当连续出现分隔符时会加入空单词，应检查j>0才计数
    }
    c=fgetc(in);
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++) // @@ 循环上限错误，应用单词长度而非单词个数，可能越界或转换不足
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
                // @@ 排序时未同步交换num数组，导致词频与单词错位
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
                       num[i]++; // @@ num[i]未初始化，且排序后索引对应错误
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ 不应加1，直接输出num[i]即可
      }
      fclose(in);
      return 0; 
}