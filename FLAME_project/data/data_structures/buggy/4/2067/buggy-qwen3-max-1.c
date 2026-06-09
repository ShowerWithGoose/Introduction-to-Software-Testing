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
    if(c>='a'&&c<'z') return 1; // @@ [The condition 'c < 'z'' excludes the letter 'z'. It should be 'c <= 'z''. Similarly, the uppercase condition excludes 'Z'. This causes 'z' and 'Z' to be treated as non-letters.]
    else if(c>'A'&&c<'Z') return 2; // @@ [The condition 'c > 'A'' excludes 'A', and 'c < 'Z'' excludes 'Z'. Should be 'c >= 'A' && c <= 'Z''. This causes 'A' and 'Z' to be treated as non-letters.]
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
    if(i>0){ // @@ [Missing handling of the last word in the file if the file doesn't end with a non-letter. The current code returns 0 without null-terminating or returning the last word if EOF is reached while reading letters. However, this line is not present in the original code — but the real issue is that after EOF, if i>0, we must return the word. The current code fails to do so. But since we cannot add lines, the error is in the loop logic below.]
        w[i] = '\0';
        return 1;
    } // @@ [But since we can't add lines, the actual bug is that the function returns 0 on EOF even if a word was partially read. The loop exits on EOF and then falls through to 'return 0;' without outputting the last word. However, the main bug causing wrong tokens is in isw().]
    return 0; // @@ [This return 0 on EOF discards the last word if the file ends without a trailing non-letter. But the more critical errors are in isw() causing incorrect tokenization (e.g., splitting "programming" into "progr", "mming", etc., because '-' and digits break words but letters like 'z'/'Z' are excluded).]
}
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;

     bfp = fopen("article.txt", "r");
     while( getword(bfp,word)) 
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