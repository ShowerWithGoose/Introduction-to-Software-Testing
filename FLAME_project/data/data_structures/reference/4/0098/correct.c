#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    char item[105];
    int count;
    struct node *next;
};
typedef struct node* Node;
char word[105];
Node Create();
void Insert(char word[],Node S);
int getword(FILE *fp);

int main(){
    FILE *fp;
    if((fp=fopen("article.txt","r"))==NULL){
        printf("没打开文件！！");
    }
    Node S=Create();
    
    while(getword(fp)){
        Insert(word,S);
        memset(word,0,sizeof(word));
    }
    Node p=S->next;
    while(p!=NULL){
        printf("%s %d\n",p->item,p->count);
        p=p->next;
    }
    fclose(fp);
    return 0;
}
Node Create(){
    Node S;
    S=(Node)malloc(sizeof(struct node));
    S->next=NULL;
    return S;
}
void Insert(char word[],Node S){
    char str[105];
    Node cur,pre,tmp;
    pre=S;
    cur=S->next;
    if(S->next==NULL){
        cur=(Node)malloc(sizeof(struct node));
        strcpy(cur->item,word);
        cur->count=1;
        cur->next=NULL;
        S->next=cur;
        return;
    }
    while(cur!=NULL){
        if(strcmp(cur->item,word)==0){
            cur->count++;
            return;
        }
        else if(strcmp(cur->item,word)>0){
            tmp=(Node)malloc(sizeof(struct node));
            strcpy(tmp->item,word);
            tmp->count=1;
            tmp->next=cur;
            pre->next=tmp;
            return;
        }
        pre=pre->next;
        cur=cur->next;
    }
    //插到结尾
    tmp=(Node)malloc(sizeof(struct node));
    strcpy(tmp->item,word);
    tmp->count=1;
    tmp->next=NULL;
    pre->next=tmp;
}
int getword(FILE *fp){
    char ch;
    int i=0;
    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)){
            if(isupper(ch)) ch=ch-'A'+'a';
            word[i++]=ch;
            while(((ch=fgetc(fp))!=EOF)&&isalpha(ch)){
                if(isupper(ch)) ch=ch-'A'+'a';
                word[i++]=ch;
            }
            word[i]='\0';
            return 1;
        }
    }
    return 0;
}

