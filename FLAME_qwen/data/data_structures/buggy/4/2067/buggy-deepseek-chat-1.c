#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXWORD  32
struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; 
struct node *Wordlist = NULL; 
int isw(char c){
    if(c>='a'&&c<'z') return 1; // @@ The condition should be c<='z' instead of c<'z', otherwise 'z' is not recognized as a lowercase letter.
    else if(c>'A'&&c<'Z') return 2; // @@ The condition should be c>='A' and c<='Z' instead of c>'A' and c<'Z', otherwise 'A' and 'Z' are not recognized as uppercase letters.
    else return 0;
}
int getword(FILE *bfp,char *w){
    char c;
    int i=0;
    while((c=fgetc(bfp))!=EOF){
       if(isw(c)){
           if(isw(c)==2) c=c-'A'+'a';
       w[i++]=c;
       
       }
       else if((!isw(c))&&i){
           w[i]='\0';
       return 1;
       }
    }
    return 0; // @@ When EOF is reached and no word was being read, the function should return EOF (or -1) to signal end-of-file, not 0, because 0 is a valid return value for a word of length 0 (which shouldn't happen). The reference program returns EOF.
}
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;

     bfp = fopen("article.txt", "r");
     while( getword(bfp,word)) // @@ The loop condition should check for EOF, not just non-zero. Since getword returns 0 on EOF, this loop will exit correctly, but the function should return EOF to match the reference program's logic.
        if(searchWord(word) == -1) { 
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=Wordlist; p != NULL; p=p->link) 
        printf("%s %d\n", p->word, p->count);
    return 0;
} 


int insertWord(struct node  *p, char *w)
{
      struct node  *q;

      q = (struct node * )malloc(sizeof(struct node));
      if(q == NULL) return -1;
      strcpy(q->word, w);
      q->count = 1;
      q->link = NULL;              
      if(Wordlist == NULL) 
           Wordlist = q;
      else if (p == NULL){
           q->link = Wordlist;
           Wordlist = q;
       }
       else {
           q->link = p->link;
           p->link = q;
       }
      return 0;
}
int searchWord(char *w)
{
struct  node *p, *q=NULL; 
for(p=Wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0) 
 break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q, w);
}