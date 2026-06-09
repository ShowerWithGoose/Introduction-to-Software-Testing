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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ Logical error: The condition uses AND (&&) instead of OR (||). A character cannot be both lowercase and uppercase simultaneously. Also, it excludes boundary characters 'a', 'z', 'A', 'Z' due to strict inequality. It should be ((c>='a'&&c<='z') || (c>='A'&&c<='Z')).
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ Incomplete delimiter handling: Only space and carriage return (13) are treated as delimiters. Punctuation marks (like '.', ';', ',') and newlines ('\n', which is 10, not just 13) are ignored, causing them to be included in words or mishandled. It should check for non-alphabetic characters generally or include all relevant punctuation and newline characters.
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
        for(j=0;j<n;j++) // @@ Logic error in loop bound: The inner loop iterates 'j' up to 'n' (number of words), but it should iterate up to the length of the current word string (strlen(word[i])) to convert characters to lowercase. Iterating up to 'n' accesses out-of-bounds memory for short words or fails to process long words correctly if n < word length.
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