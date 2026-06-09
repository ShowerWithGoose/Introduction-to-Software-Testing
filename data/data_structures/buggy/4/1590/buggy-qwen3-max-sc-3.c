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
    if(i>0){ // @@ [When EOF is reached and there's a word being built (i>0), it should be returned as a valid word. The original code returns EOF immediately without handling the last word in the file.]
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
    q->link = NULL; // @@ [Missing initialization of q->link to NULL, which can cause undefined behavior when traversing the list.]
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
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ [The loop update 'q=p,p=p->link' is missing; current code does not track the previous node 'q', which is needed for correct insertion in sorted order. Without 'q', the insertion point is incorrect.]
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ [Because 'q' is never updated in the loop, it remains NULL, causing new words to always be inserted at the head, breaking lexicographical order.]
}
int main()
{
    struct node *p;
    FILE *f1=fopen("article.txt","r");
    if(f1 == NULL) return 1; // @@ [Missing check for successful file opening; if file doesn't exist, fgetc will cause undefined behavior.]
    while(getword(f1,word)!=EOF){
        searchword(word);
    }
    fclose(f1); // @@ [File is not closed, though not critical for correctness, but good practice. However, the main issue is logic errors above.]
    for(p=list; p != NULL; p=p->link) 
    printf("%s %d\n", p->word, p->cnt);
    return 0;
}