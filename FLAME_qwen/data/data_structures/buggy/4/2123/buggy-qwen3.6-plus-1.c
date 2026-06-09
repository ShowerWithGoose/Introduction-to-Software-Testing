/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int num[100]; // @@ Array 'num' is not initialized to zero, causing undefined behavior when incremented. Also, size 100 may be too small if the number of words exceeds 100.
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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ Logical error: A character cannot be both lowercase and uppercase simultaneously. Should use '||' instead of '&&', and include '=' for boundaries (>=, <=).
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ Only handles space and carriage return. Fails to handle newline ('\n') and other non-letter delimiters, causing words to not be properly terminated or punctuation to be included.
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
        for(j=0;j<n;j++) // @@ 'n' represents the number of words, not the length of the current word. Should iterate up to the string length or max word size (e.g., j < strlen(word[i]) or j < 100).
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
                       num[i]++; // @@ 'num' array was not initialized, so incrementing it yields garbage values. Also, 'i' can exceed 99, causing out-of-bounds access.
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ 'num[i]' contains uninitialized/garbage values due to lack of initialization, leading to incorrect output.
      }
      fclose(in);
      return 0; 
}