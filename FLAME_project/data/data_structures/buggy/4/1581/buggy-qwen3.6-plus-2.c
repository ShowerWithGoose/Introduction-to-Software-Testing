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
            }else if((line[i]==' ')||(top>0)){ // @@ The condition (top>0) triggers word processing for any non-letter character (like digits or punctuation). This causes empty strings or partial words to be processed incorrectly when top is 0 but the character is not a space (e.g., digit '1'). It should strictly check if a word has been accumulated (top > 0) AND the current character is a delimiter. However, the logic `else if ((line[i]==' ') || (top>0))` means if top>0, it processes the word even if the current char is a digit. This is actually intended to delimit words by non-letters. The real issue is likely that it processes an empty word if top==0 and line[i]==' ', or it fails to reset properly. Let's look closer. If `top==0` and `line[i]` is a digit, the first two ifs fail. The third `else if` checks `(line[i]==' ') || (top>0)`. If it's a digit, `line[i]==' '` is false. `top>0` is false. So it skips. This is correct for digits inside "since1972". Wait, "since1972" -> s,i,n,c,e are added. Then '1'. '1' is not letter. `top` is 5. `line[i]==' '` is false. `top>0` is true. So it enters block. `W[5]='\0'`, `top=0`, `search("since")`. Correct. Then '9'. `top` is 0. `line[i]==' '` false. `top>0` false. Skips. Correct. Then '7'. Skips. Then '2'. Skips. Then '.'. `top` is 0. `line[i]==' '` false. `top>0` false. Skips. Then ' '. `top` is 0. `line[i]==' '` true. Enters block. `W[0]='\0'`, `top=0`, `search("")`. This searches for an empty string! This is the bug.
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
    return ;
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