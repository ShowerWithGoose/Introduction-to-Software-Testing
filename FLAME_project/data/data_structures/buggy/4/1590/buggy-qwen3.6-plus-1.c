# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
struct node {
    char word[50];
    int cnt;
    struct node *link;
} ; 
struct node *list=NULL;
char word[50];

int getword(FILE *fp,char word[])
{
    int i=0;
    char temp;
    while((temp=fgetc(fp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0){
            word[i]='\0';
            return 0;
        }
    }
    if (i > 0) { // @@ The function returns EOF if the file ends with a word (no trailing non-alpha character), causing the last word to be ignored. We must check if a word was accumulated before returning EOF.
        word[i]='\0';
        return 0;
    }
    return EOF;
}
int insertword(struct node *p,char *w)
{
    struct node *q; 
    q=(struct node*)malloc(sizeof(struct node));
    strcpy(q->word, w);
    q->cnt=1;
    q->link = NULL; // @@ The new node's link field is not initialized to NULL. If inserted at the end (p is not NULL and p->link is NULL) or in the middle, this might be okay due to logic, but if inserted at head when list is not NULL (p==NULL case), q->link is set. However, in the 'else' block, q->link takes p->link. If p is the last node, p->link is NULL, so q->link becomes NULL. But if q is allocated, its members are uninitialized. Specifically, if the list is empty, list=q, and q->link is garbage if not set. Wait, in the first if (list==NULL), q->link is not set. It should be NULL.
    if(list==NULL){
        list=q;
    }//first added 
    else if(p==NULL){ 
        q->link=list;
        list=q;
    }
    else {
        q->link=p->link;
        p->link=q;//inserted 
    }
    return 0;
}
int searchword(char *w)
{ 
    struct  node *p, *q=NULL; 
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ The variable q is used to track the previous node for insertion, but it is not updated in the loop. It remains NULL. It should be updated to p before p moves to the next node.
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ Because q was not updated in the loop, it is always NULL (or garbage if not initialized). This causes new words to always be inserted at the head of the list instead of the correct sorted position, resulting in incorrect order and potentially duplicate entries if logic fails.
}
int main()
{
    struct node *p;
    FILE *f1=fopen("article.txt","r");
    while(getword(f1,word)!=EOF){
        searchword(word);
    }
    for(p=list; p != NULL; p=p->link) 
    printf("%s %d\n", p->word, p->cnt);
    return 0;
}