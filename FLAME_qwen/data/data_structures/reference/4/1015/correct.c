#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024
struct lnode {
    char word[MAXWORD];
    int count;
};
int getWord(FILE *bfp,char *w);
int searchWord(struct lnode list[], char *w);
int insertWord(struct lnode list[ ],  int pos, char *w);
int N=0;
int main()
{
    struct lnode wordlist[MAXSIZE];
    int i;	
    char filename[MAXWORD], word[MAXWORD];
    FILE *bfp;

    
    if((bfp = fopen("article.txt", "r")) == NULL){
        fprintf(stderr, "%s  can't open!\n",filename);
        return -1;
     }
     
     
     
    while( getWord(bfp,word) != EOF)
        if(searchWord(wordlist, word) == -1) {
            fprintf(stderr, "Wordlist is full!\n");
            return -1;
            
        }
    char temp[100];
    int temp2;
    for(int j=0;j<N;j++) {
    	for(int k=j+1;k<N;k++)
		if(strcmp(wordlist[j].word,wordlist[k].word)>0) {
			strcpy(temp,wordlist[j].word);
			strcpy(wordlist[j].word,wordlist[k].word);
			strcpy(wordlist[k].word,temp); 
			temp2=wordlist[j].count;
			wordlist[j].count=wordlist[k].count;
			wordlist[k].count=temp2;
		}
		
	}
    for(i=0; i<= N-1; i++)
        printf("%s %d\n", wordlist[i].word,   wordlist[i].count);
    return 0;
    
} 


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

int insertWord(struct lnode list[ ], int pos, char *w)
{
      int i;

      if  (N == MAXSIZE) return -1; 
              
     for(i=N-1; i>=pos; i--){
          strcpy(list[i+1].word, list[i].word);
          list[i+1].count = list[i].count;
     }
    strcpy(list[pos].word, w);
    list[pos].count = 1;
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
            list[mid].count++;
   return 0;
	}
}
return insertWord(list, low, w);
}



