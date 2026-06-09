#include <stdio.h>
#include <stdlib.h>
#include <string.h> // @@ Missing #include <ctype.h>, which is required for the isalpha() function used in main(), causing a compilation error.
#define MAXWORD 100000
#define tolower(c)  (c>='A'&&c<='Z' ? 'a'-'A'+c:c) // @@ Custom macro redefines tolower; recommend using the standard library version after including <ctype.h> to avoid conflicts and ensure correct behavior.
struct node{
    char word[MAXWORD];
    int count;
    struct node *link;
}; 
struct node *Wordlist=NULL;
int getWord(FILE *fp,char *word);
int searchWord(char *w);
int insertWord(struct node *p,char *w);
int flag;

int main(){
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;
    if((bfp=fopen("article.txt","r"))==NULL){
        printf("article can't open!\n");
        return -1;
    }
    while(getWord(bfp,word)!=-1){
        if(isalpha(word[0])){ // @@ Compilation error: 'isalpha' is undeclared due to missing <ctype.h> header.
            if(searchWord(word)==-1){
                printf("Memory is full!\n");
                return -1;
               }
        }
    }
    for(p=Wordlist;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
    

    return 0;
}
int searchWord(char *w){
    struct  node *p,*q=NULL;
    for(p=Wordlist;p!=NULL;q=p,p=p->link){
        if(strcmp(w,p->word)<0)
            break;
        else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;    
        }
    }
    return insertWord(q,w);
}
int insertWord(struct node *p,char *w){
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(q==NULL)return -1;
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(Wordlist==NULL)//Ϊգ½ڵΪͷڵ
        Wordlist=q;
    else if(p==NULL){//½ڵǰһΪ
        q->link=Wordlist;
        Wordlist=q;//½ڵ뵽ͷ
    }
    else{
        q->link=p->link;
        p->link=q;
    }
    return 0;
}
int getWord(FILE *fp,char *word){ // @@ Logical error: Function does not correctly implement word extraction per spec; fails to skip leading non-letters and mishandles delimiter sequences.
    int i=0;
    while(fscanf(fp,"%c",&word[i])!=EOF){ // @@ Logical error: Inefficient char-by-char read; loop logic doesn't properly accumulate only letters and loses the last word if file ends without a trailing delimiter.
        if((word[i]>='A'&&word[i]<='Z')||(word[i]>='a'&&word[i]<='z')){
            flag = 0; // @@ Logical error: Global 'flag' retains state across function calls, corrupting word termination logic on subsequent newlines.
            word[i] = tolower(word[i]);
            i++;
        }else if(word[i]==' '){        //\n // @@ Logical error: Only checks for space; other non-letter characters (punctuation, tabs) are ignored and will overwrite the buffer in the next iteration.
            word[i]='\0';
            return 1;
        }else if(word[i]=='\n'){ // @@ Logical error: When flag!=0, returns without null-terminating 'word', leaving stale data from previous calls and causing duplicate/incorrect output.
            if(flag==0){
                word[i]='\0';
                flag = 1;
            }
            return 1;
        }
    }
    return -1; // @@ Logical error: If the file ends immediately after a word (no trailing space/newline), the accumulated word is discarded instead of being returned.
}