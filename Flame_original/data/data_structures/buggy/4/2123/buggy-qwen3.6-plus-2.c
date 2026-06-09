/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int num[100]; // @@ Uninitialized array, contains garbage values. Should be initialized to 0.
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
        if((c>'a'&&c<'z')&&(c>'A'&&c<'Z')) // @@ Logical error: uses && which is always false; should use ||. Also strict inequalities exclude boundary letters 'a','z','A','Z'.
        {
              word[i][j]=c;
              j++;
        }
        else if(c==' '||c==13) // @@ Incomplete condition for word boundaries; fails to handle '\n' and other non-letter characters.
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
        for(j=0;j<n;j++) // @@ Iterates j up to n (word count) instead of string length, causing out-of-bounds access or incorrect conversion.
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
                       num[i]++; // @@ num array is uninitialized, incrementing garbage values. Also size 100 may cause overflow if n>100.
                       strcpy(word[j],"\0");
                 }
               }
          }
      }
      for(i=0;i<n;i++)
      {
           if(strlen(word[i])>0)
            printf("%s %d\n",word[i],num[i]+1); // @@ Prints uninitialized/garbage count due to num not being initialized.
      }
      fclose(in);
      return 0; 
}