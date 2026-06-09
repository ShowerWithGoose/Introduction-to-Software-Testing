#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024

struct lnode {
    char word[MAXWORD];
    int coun;
};
int N=0;
int getWord(FILE *fp, char *w)
{
     int c;
    while(!isalpha(c=fgetc(fp)))
        if(c == EOF) return c;
       else continue;
    do  {
         *w++ = tolower(c);
    } while(isalpha(c=fgetc(fp)));
    *w='\0';
   return 1;
}

int insertWord(struct lnode lis[ ], int pos, char *w)
{
      int i;

      if  (N == MAXSIZE) return -1;

     for(i=N-1; i>=pos; i--){
          strcpy(lis[i+1].word, lis[i].word);
          lis[i+1].coun = lis[i].coun;
     }
    strcpy(lis[pos].word, w);
    lis[pos].coun = 1;
     N++;
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
            list[mid].coun++;
            return 0;
	}
}
return insertWord(list, low, w);
}

int main()
{
    struct lnode wordlist[MAXSIZE];
    int i;
    char filename[MAXWORD], word[MAXWORD];
    FILE *bfp;
    scanf("%s", filename);
    if((bfp = fopen("article.txt","r")) == NULL){
        fprintf(stderr, "%s can't open!\n",filename);
        return -1;
     }
    while( getWord(bfp,word) != EOF)
        if(searchWord(wordlist, word) == -1) {
            fprintf(stderr,"Worldlist is full!\n");
            return -1;
        }
    for(i=0; i<= N-1; i++)
        printf("%s %d\n",wordlist[i].word,wordlist[i].coun);
    return 0;
}


