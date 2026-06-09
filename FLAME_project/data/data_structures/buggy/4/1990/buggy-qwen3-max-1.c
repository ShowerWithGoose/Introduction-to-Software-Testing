#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100000
#define tolower(c)  (c>='A'&&c<='Z' ? 'a'-'A'+c:c)
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
        if(isalpha(word[0])){
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
int getWord(FILE *fp,char *word){
    int i=0;
    while(fscanf(fp,"%c",&word[i])!=EOF){
        if((word[i]>='A'&&word[i]<='Z')||(word[i]>='a'&&word[i]<='z')){
            flag = 0;
            word[i] = tolower(word[i]);
            i++;
        }else if(word[i]==' '){        //\n
            word[i]='\0';
            return 1;
        }else if(word[i]=='\n'){
            if(flag==0){
                word[i]='\0';
                flag = 1;
            }
            return 1;
        }
    }
    return -1; // @@ [The function does not properly handle the case where the file ends without a space or newline after the last word. It returns -1 without null-terminating the word buffer, so the last word may be lost or corrupted. Also, it fails to correctly extract words that are adjacent to non-alphabetic characters like digits or punctuation (e.g., "C since1972.C" should yield "c" and "since", but the current logic stops only at space or newline, not at other non-letter characters).]
}