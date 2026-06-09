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
    return EOF; // @@ If the file ends with a letter (no following non-letter), the last word is not null-terminated and is lost because this function returns EOF without processing the word.
}
int insertword(struct node *p,char *w)
{
    struct node *q; 
    q=(struct node*)malloc(sizeof(struct node));
    strcpy(q->word, w);
    q->cnt=1; // @@ The new node's link field is not initialized to NULL, which can lead to undefined behavior when traversing the list.
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
    for(p=list;p!=NULL;p=p->link){ // @@ The loop does not update the previous node pointer q, which is needed for correct insertion. The loop should be 'for(p=list,q=NULL; p!=NULL; q=p, p=p->link)'.
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(p,w); // @@ Should pass the previous node q instead of p. After the loop, p points to the node that is greater than w (or NULL), and q should be the node before it (or NULL for insertion at front). Inserting after p (or at front if p==NULL) breaks lexicographic order.
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