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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ [Error: The condition uses && instead of ||, so it requires c to be simultaneously between 'a' and 'z' AND between 'A' and 'Z', which is impossible. It should be (c>='a'&&c<='z')||(c>='A'&&c<='Z') to correctly identify letters. Also missing the equal sign for boundary characters like 'a', 'z', 'A', 'Z'.]
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ [Error: Only handles spaces and carriage return (13) as delimiters, but does not handle other punctuation like periods, semicolons, newlines (10), etc. This causes words to be concatenated with punctuation or missed entirely.]
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
        for(j=0;j<n;j++) // @@ [Error: The inner loop should be j<strlen(word[i]) to convert each character of the word, not j<n which goes out of bounds and may access uninitialized memory.]
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
                       num[i]++;
                       strcpy(word[j],"\0"); // @@ [Error: Setting word[j] to empty string may cause issues in sorting and later comparisons; also num array is not initialized to 0, leading to undefined behavior.]
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ [Error: num[i] is not initialized to 0, so adding 1 gives incorrect counts. Also the output starts from i=0 but the first word may be empty due to leading delimiters, causing extra blank lines.]
      }
      fclose(in);
      return 0; 
}