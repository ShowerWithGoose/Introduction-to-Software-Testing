#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
FILE *fp1;
int num[1000];
char word[1000][100],temp[100];
int i,j,k,m,n,c;
int main() 
{ 
  fp1=fopen("article.txt","r");
  c=fgetc(fp1);
  while(c!=EOF)
  {
    if(isalpha(c)>0)
    {
      word[i][j]=c;
      j++;
    }
    else if(isspace(c)>0||ispunct(c)>0)
    {
      word[i][j]='\0';
      j=0;
      i++;
      n++;
    }
    c=fgetc(fp1);
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
        strcpy(temp,word[i]);
        strcpy(word[i],word[j]);
        strcpy(word[j],temp);
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
  fclose(fp1);
  system("pause");
  return 0; 
}




