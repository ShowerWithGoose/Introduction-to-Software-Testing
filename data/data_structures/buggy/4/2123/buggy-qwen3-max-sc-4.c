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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ [Logical error: condition is always false because a character cannot be both between 'a' and 'z' AND between 'A' and 'Z'. Also, the bounds are exclusive (using < instead of <=), so 'a', 'z', 'A', 'Z' are excluded. Should use isalpha() or proper inclusive range checks with ||]
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ [Incomplete word delimiter handling: only handles space and carriage return (13), but not newline (10), tab, punctuation, etc. According to problem, any non-letter should delimit a word.]
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
        for(j=0;j<n;j++) // @@ [Incorrect inner loop bound: should iterate over characters in word[i], not up to n (number of words). This causes out-of-bound access and incorrect tolower application.]
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
                       num[i]++; // @@ [Uninitialized array: num[] is not initialized to zero, so incrementing leads to undefined behavior.]
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ [Because num[i] is uninitialized, num[i]+1 is unpredictable. Also, if a word appears only once, num[i] remains garbage, not 0.]
      }
      fclose(in);
      return 0; 
}