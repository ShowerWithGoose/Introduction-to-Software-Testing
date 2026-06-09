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
    if(c>='a'&&c<'z') return 1; // @@ [The condition should be c<='z', not c<'z'; similarly for uppercase, it should be c<='Z'. This causes 'z' and 'Z' to be excluded from being recognized as letters.]
    else if(c>'A'&&c<'Z') return 2; // @@ [The condition should be c>='A' && c<='Z', not c>'A' && c<'Z'; this excludes 'A' and 'Z' from being recognized as uppercase letters.]
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
    if(i>0) { w[i]='\0'; return 1; } // @@ [Missing handling of the last word in the file if the file doesn't end with a non-letter character. The current code returns 0 at EOF without null-terminating or returning the last word.]
    return 0;
}
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;

     bfp = fopen("article.txt", "r");
     if (bfp == NULL) { // @@ [Missing check for fopen failure; if the file doesn't exist, the program will crash on fgetc.]
         fprintf(stderr, "Cannot open file article.txt\n");
         return -1;
     }
     while( getword(bfp,word)) 
        if(searchWord(word) == -1) { 
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=Wordlist; p != NULL; p=p->link) 
        printf("%s %d\n", p->word, p->count);
    fclose(bfp); // @@ [Missing fclose call before return, leading to resource leak. Though not a compilation error, it's a bug. However, the primary issue is logic errors causing wrong output. But per problem, focus on functional bugs affecting correctness.]
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