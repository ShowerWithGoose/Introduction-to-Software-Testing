#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD  32

struct node {
    char word[MAXWORD];
    int count;
    struct node* link;
};
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord(struct node *p, char *w);
struct node*Wordlist=NULL;

int main()
{
       char filename[32], word[MAXWORD];
    FILE *bfp;
    struct node *p;


    if((bfp = fopen("article.txt", "r")) == NULL){
        fprintf(stderr, "%s  can¡¯t open!\n",filename);
        return -1;
     }
     while( getWord(bfp,word) != 0)
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



int getWord(FILE *fp,char *str)

{

char c;

int counter = 0;

while((c = fgetc(fp)) != EOF){

if( !isalpha(c) && (counter <= 0))
continue;

else if(!isalpha(c) && (counter > 0))
break;

str[counter++] = tolower(c);

}

str[counter] = '\0';

if(counter > 0)

return 1;

else

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

