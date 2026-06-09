#include<stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024
int N=0;
struct lnode {
    char word[MAXWORD];
    int count;
};
int getWord(FILE *fp, char w[ ])
{
     int c,i=0;
    
    while(!isalpha(c=fgetc(fp)))  
        if(c == EOF) return c;  
       else continue;
    do  {
         w[i++]= tolower(c);
    } while(isalpha(c=fgetc(fp))); 
    w[i]='\0';
   return 1;
} 
int searchWord(struct lnode list[ ], char *w)
{
int low=0, high=N-1, mid=0;
while(low <= high){
mid = (high + low) / 2;
if(strcmp( w, list[mid].word)<0)
   high = mid -1;
else if(strcmp( w, list[mid].word)>0)
   low = mid + 1;
else { 
            list[mid].count++;
   return 0;
    }
}
return insertWord(list, low, w);
}
int insertWord(struct lnode list[ ], int pos, char *w)
{
      int i;

      if  (N == MAXSIZE) return -1; 
              
     for(i=N-1; i>=pos; i--){
          list[i+1]=list[i];
     }
    strcpy(list[pos].word, w);
    list[pos].count = 1;
     N++;
     return 1;
}
int main()
{
    struct lnode wordlist[MAXSIZE];    /*µ¥´Ê±í*/
    int i;    
    char  word[MAXWORD];
    FILE *in;
    in = fopen("article.txt", "r");
    while(getWord(in,word)!=EOF)
        searchWord(wordlist,word);
    for(i=0; i<= N-1; i++)
        printf("%s  %d\n", wordlist[i].word,   wordlist[i].count); // @@ [Error: The output format has two spaces between the word and the count, but the expected output has only one space. This causes a mismatch in the output format.]
    fclose(in);
    return 0;
}