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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ [逻辑错误：条件 (c>'a'&&c<'z') 排除了 'a' 和 'z' 本身，且 (c>'A'&&c<'Z') 排除了 'A' 和 'Z'，同时使用 && 导致永远为假，因为一个字符不能同时是小写和大写。应使用 || 并包含边界，如 (c>='a'&&c<='z')||(c>='A'&&c<='Z')]
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ [逻辑错误：条件只处理空格和回车，但未处理其他非字母字符（如标点符号、制表符、换行符等），导致这些字符被忽略并可能使单词拼接出错]
        {    
              word[i][j]='\0';
              j=0;
              i+=1;
              n+=1;
    }
    c=fgetc(in);
      }
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++) // @@ [逻辑错误：内层循环 j 从 0 到 n，但 word[i] 的长度可能小于 n，导致访问越界或转换了无效字符。应使用 strlen(word[i]) 作为循环上限]
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
                       num[i]++; // @@ [逻辑错误：num 数组未初始化，应初始化为 0，否则计数结果不确定]
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1);
      }
      fclose(in);
      return 0; 
}