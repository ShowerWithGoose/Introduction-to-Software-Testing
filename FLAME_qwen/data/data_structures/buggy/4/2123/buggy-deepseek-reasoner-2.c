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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ Logical error: should use '||' instead of '&&', and should include '>=', '<='. This condition is always false, so no letters are captured.
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ Incomplete delimiter: missing newline ('\n') and tab, causing words to be concatenated across lines.
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
        for(j=0;j<n;j++)
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
                       num[i]++; // @@ Uninitialized variable 'num' causes undefined behavior. Should initialize num array to 0 before use.
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ 'num[i]' may be uninitialized for words with no duplicates, leading to garbage count output.
      }
      fclose(in);
      return 0; 
}