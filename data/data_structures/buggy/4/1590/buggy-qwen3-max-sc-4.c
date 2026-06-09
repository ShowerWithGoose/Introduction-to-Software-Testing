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
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ [The loop update clause is missing 'q=p', which breaks the intended insertion logic and causes incorrect linking during insertion. The original reference program had 'q=p' in the loop increment part, but this buggy version omits it, leading to wrong predecessor tracking.]
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ [Because 'q' is not updated correctly in the loop above (missing 'q=p' in loop increment), 'q' remains NULL when inserting a word that should go in the middle or end of the list, causing incorrect insertion position and breaking lexicographical order.]
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