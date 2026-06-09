#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024
struct lnode {
    char word[MAXWORD];
    int count;int ext;
};
void sortword(struct lnode array[],int n);
void placeword(struct lnode array[],int n);
int n=0;
int main()
{
    struct lnode wordlist[MAXSIZE];
    FILE *fp;
    int i=0,j=0;
    fp=fopen("article.txt","r");
    char t;wordlist[0].count=wordlist[0].ext=1;
    while((t=getc(fp))!=EOF)
    {
     if(isalpha(t))
     {
      if(islower(t)){wordlist[n].word[i]=t;i++;}
      else{wordlist[n].word[i]=t+'a'-'A';i++;}
     }
    else if(ispunct(t)||isspace(t))
      {
       wordlist[n].word[i]='\0';
       i=0;n++;wordlist[n].count=wordlist[n].ext=1;
      }
    }n++;
    sortword(wordlist,n);
for(i=0;i<n;i++)
  {
  for(j=i;j<n;j++)
   {
    if((strcmp(wordlist[i].word,wordlist[j].word)==0)&&(i!=j))
     {wordlist[i].count++;wordlist[j].ext=0;}
   }
  }
    for(i=1; i<n; i++)
  { if(wordlist[i].ext)printf("%s %d\n", wordlist[i].word, wordlist[i].count);}
    return 0;
}
void sortword(struct lnode array[],int n)
{
int i,j;
struct lnode tmp;
for(i=0;i<n;i++)
 {
  for(j=i;j<n;j++)
   {
    if(strcmp(array[i].word,array[j].word)>0)
     {strcpy(tmp.word,array[i].word);
      strcpy(array[i].word,array[j].word);
      strcpy(array[j].word,tmp.word);}
   }
 }
}

