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
    if (i > 0) { // @@ [If the file ends without a non-alphabetic character after the last word, the last word won't be returned. The original reference handles this by returning the word after EOF if i>0, but this version doesn't. However, this is a logic error, not compilation. But note: the actual compilation error is likely due to missing initialization of `q->link` in insertword.]
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
    q->link = NULL; // @@ [Missing initialization of q->link leads to undefined behavior when traversing the list. This is a logic/runtime error, but may cause crashes that mimic compilation issues in some environments. However, the reported error is "gcc: not found", which is actually an environment issue, not code error. But assuming the real issue is in code: the main bug is in searchword passing wrong pointer.]
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
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ [The loop update is incorrect: it should track the previous node (q) properly to insert in order. The current loop does `q=p,p=p->link` but the condition breaks before updating q when inserting at end or middle. Also, after loop, p is NULL or points to first greater word, but q is previous. However, the call passes `p` instead of `q` to insertword.]
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ [Should pass `q` (the previous node) not `p`. In the buggy code below, it's passing `p`, which is wrong. But in this source code line, it's actually `q` — wait, looking again: in the provided buggy source, this line says `return insertword(p,w);` — yes! So this line is wrong.]
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