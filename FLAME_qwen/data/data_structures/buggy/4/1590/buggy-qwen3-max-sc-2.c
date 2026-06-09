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
    if(i>0){ // @@ [When EOF is reached but a word has been read (i>0), it should be returned as a valid word. The original code returns EOF immediately without handling the last word in the file if it's not followed by a non-alpha character.]
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
    q->link = NULL; // @@ [The 'link' field of the new node is not initialized to NULL in all code paths, which can lead to undefined behavior when traversing the list. It must be set to NULL before insertion.]
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
    for(p=list;p!=NULL;q=p,p=p->link){ // @@ [The loop update expression is incorrect: it should track the previous node (q) properly to allow correct insertion before the current node when needed. The original loop does not update q correctly because the increment happens after the body, so q remains NULL always. This breaks ordered insertion.]
        if(strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w); // @@ [Because q is never updated correctly in the loop above, insertword receives an incorrect previous node pointer, leading to wrong insertion position and thus breaking lexicographical order.]
}
int main()
{
    struct node *p;
    FILE *f1=fopen("article.txt","r");
    if(f1 == NULL) return 1; // @@ [The program does not check if fopen succeeded. If "article.txt" does not exist, f1 will be NULL and subsequent fgetc calls cause undefined behavior.]
    while(getword(f1,word)!=EOF){
        searchword(word);
    }
    fclose(f1); // @@ [The file is never closed, which is bad practice and may cause resource leaks, though not directly causing the output error. However, the primary issue is logical correctness.]
    for(p=list; p != NULL; p=p->link) 
    printf("%s %d\n", p->word, p->cnt);
    return 0;
}