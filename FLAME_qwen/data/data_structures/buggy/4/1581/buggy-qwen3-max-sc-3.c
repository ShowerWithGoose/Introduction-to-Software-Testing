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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, 'in' will be NULL, leading to undefined behavior when passed to fgets. However, the primary error here is that global variable 'list' is uninitialized, causing segmentation fault during search/insert.]
    int top=0,i;
    while((fgets(line,10000,in))!=NULL){
        int len=strlen(line);
        for(i=0;i<len;i++){
            if(line[i]<='z'&&line[i]>='a'){
                W[top++]=line[i];
            }else if(line[i]<='Z'&&line[i]>='A'){
                W[top++]=line[i]+'a'-'A';
            }else if((line[i]==' ')||(top>0)){ // @@ [This condition triggers insertion even on non-space delimiters (like punctuation), but also inserts empty string when top==0 and delimiter occurs. More critically, it skips inserting the last word if the line doesn't end with space or delimiter.]
                W[top]='\0';
                top=0;
                search(W); // @@ [Passing potentially empty string "" when top was 0 before this block; also, 'list' is never initialized to NULL globally, so initial comparisons are against garbage pointer.]
            }
        }
    }
    struct node *p;
    for(p=list;p!=NULL;p=p->link){
        printf("%s %d\n",p->word,p->num);
    }
    fclose(in);
    return ; // @@ [Missing return value; should be 'return 0;' for int main()]
}
void insert(char *x,struct node *p){
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    if(q==NULL)return;
    strcpy(q->word,x);
    q->num=1;
    q->link=NULL;
    if(list==NULL){ // @@ ['list' is a global pointer never initialized to NULL, so this check may fail unpredictably. Should initialize 'struct node *list = NULL;' at declaration.]
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