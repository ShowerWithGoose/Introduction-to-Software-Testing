/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int num[100]; // @@ The array 'num' is not initialized, leading to undefined values when incremented later. It should be initialized to 0.
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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ The logical condition is incorrect. It uses AND (&&) instead of OR (||), and excludes boundary characters 'a', 'z', 'A', 'Z'. It should be ((c>='a'&&c<='z') || (c>='A'&&c<='Z')). As written, this condition is always false because a character cannot be both lowercase and uppercase simultaneously.
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ This condition only handles spaces and carriage returns as delimiters. It fails to handle other non-letter characters like punctuation ('.', ';', etc.) or newlines ('\n'), which means words attached to punctuation won't be terminated correctly, or lines won't be processed correctly. It should check if the character is NOT a letter.
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
        for(j=0;j<n;j++) // @@ The inner loop bound is incorrect. It iterates 'n' times (number of words) instead of iterating through the length of the current word string. It should be strlen(word[i]) or similar, otherwise it accesses out-of-bounds memory or processes garbage data.
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