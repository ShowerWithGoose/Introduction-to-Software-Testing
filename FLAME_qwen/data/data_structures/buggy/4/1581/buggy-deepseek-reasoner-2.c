#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
FILE *in;
char line[10005];
char W[105];
struct node{
    char word[105];
    int num;
    struct node *link;
};
struct node *list;
int search(char *x);
void insert(char *x,struct node* p);
int main(){
    in=fopen("article.txt","r");
    int top=0,i;
    while((fgets(line,10000,in))!=NULL){
        int len=strlen(line);
        for(i=0;i<len;i++){
            if(line[i]<='z'&&line[i]>='a'){
                W[top++]=line[i];
            }else if(line[i]<='Z'&&line[i]>='A'){
                W[top++]=line[i]+'a'-'A';
            }else if((line[i]==' ')||(top>0)){ // @@ This condition incorrectly triggers an empty word when a space appears with top==0. It should only process a word when top>0.
                W[top]='\0';
                top=0;
                search(W);
            }
        }
    }
    struct node *p;
    for(p=list;p!=NULL;p=p->link){
        printf("%s %d\n",p->word,p->num);
    }
    fclose(in);
    return ; // @@ The main function is declared to return int, but this statement does not return a value. Should be "return 0;".
}
void insert(char *x,struct node *p){
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    if(q==NULL)return;
    strcpy(q->word,x);
    q->num=1;
    q->link=NULL;
    if(list==NULL){
        list=q;
        return;
    }
    if(p==NULL){
        q->link=list;
        list=q;
        return;
    }
    q->link=p->link;
    p->link=q;
}
int search(char *x){
    struct node *p,*q=NULL;
    for(p=list;p!=NULL;q=p,p=p->link){
        if(strcmp(x,p->word)<0)break;
        if(strcmp(x,p->word)==0){
            p->num++;
            return 0;
        }
    }
    insert(x,q);
    return 1;
}