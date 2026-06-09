# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define MAXWORD  50

struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
} ; 
struct node *Wordlist = NULL; 

int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main()
{
    char filename[32]={"article.txt"};
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;

    if((bfp = fopen(filename, "r")) == NULL){ 
        fprintf(stderr, "%s  can¡¯t open!\n",filename);
        return -1;
    }
    
    while( getWord(bfp,word) != EOF) 
        if(searchWord(word) == -1) { 
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    p=Wordlist;
    while(p != NULL)
    {
	
        printf("%s %d\n", p->word, p->count);
         p=p->link;}

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
    p=Wordlist;
    while(p != NULL)
	{
        if(strcmp(w, p->word) < 0)
            break;
        else if(strcmp(w, p->word) == 0){
            p->count++;
            return 0 ;
        }
        q=p,p=p->link;
    }
    return insertWord(q, w);
}


int getWord(FILE *bfp,char word[])
{
    int i=0;
    char temp;

    while((temp=fgetc(bfp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0){
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}



