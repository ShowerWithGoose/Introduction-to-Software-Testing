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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ [The condition is logically incorrect: it uses && instead of ||, and uses strict inequalities which exclude 'a', 'z', 'A', 'Z'. Also, it doesn't handle non-alphabetic characters correctly.]
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ [Only checks for space and carriage return (13), but not newline (10) or other non-letter delimiters like punctuation. This will fail to split words properly on newlines or punctuation.]
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
        for(j=0;j<n;j++) // @@ [Inner loop bound should be strlen(word[i]), not n. This causes out-of-bound access and incorrect tolower() calls on uninitialized parts of word[i].]
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
                       num[i]++; // @@ [num array is uninitialized; using num[i]++ leads to undefined behavior. Should initialize num to zeros.]
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ [Because num[i] was never initialized to 0, num[i]+1 is unpredictable. Also, words that appear once will print as 1 only if num[i] happened to be 0, which is not guaranteed.]
      }
      fclose(in);
      return 0; 
}