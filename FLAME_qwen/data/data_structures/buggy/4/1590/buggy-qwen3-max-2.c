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
    return EOF;
}
int insertword(struct node *p,char *w)
{
    struct node *q; 
    q=(struct node*)malloc(sizeof(struct node));
    strcpy(q->word, w);
    q->cnt=1;
    q->link = NULL; // @@ [Missing initialization of q->link to NULL, leading to undefined behavior when traversing the list]
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
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ [Loop update clause is incorrect: 'q' should be updated before 'p' moves, but current syntax causes 'q' to lag incorrectly; also missing proper insertion point tracking for lexicographical order]
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ [Passing 'q' which may not be the correct predecessor for insertion due to flawed loop logic]
}
int main()
{
    struct node *p;
    FILE *f1=fopen("article.txt","r");
    if (f1 == NULL) return 1; // @@ [Missing check for file open failure, which can cause segmentation fault on invalid file]
    while(getword(f1,word)!=EOF){
        searchword(word);
    }
    fclose(f1); // @@ [Missing fclose leads to resource leak, though not directly causing wrong output, it's a good practice and sometimes required in strict environments]
    for(p=list; p != NULL; p=p->link) 
    printf("%s %d\n", p->word, p->cnt);
    return 0;
}