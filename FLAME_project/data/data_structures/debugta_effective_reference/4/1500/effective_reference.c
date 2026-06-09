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
char ch2[105];
Node Create();
void Insert(char ch2[],Node fir);
int getword(FILE *fp);

int main(){
    FILE *fp;
    if((fp=fopen("article.txt","r"))==NULL){
        printf("没打开文件！！");
    }
    Node fir=Create();
    
    while(getword(fp)){
        Insert(ch2,fir);
        memset(ch2,0,sizeof(ch2));
    }
    Node p=fir->next;
    while(p!=NULL){
        printf("%s %d\n",p->item,p->count);
        p=p->next;
    }
    fclose(fp);
    return 0;
}
Node Create(){
    Node fir;
    fir=(Node)malloc(sizeof(struct node));
    fir->next=NULL;
    return fir;
}
void Insert(char ch2[],Node fir){
    char str[105];
    Node cur,pre,tmp;
    pre=fir;
    cur=fir->next;
    if(fir->next==NULL){
        cur=(Node)malloc(sizeof(struct node));
        strcpy(cur->item,ch2);
        cur->count=1;
        cur->next=NULL;
        fir->next=cur;
        return;
    }
    while(cur!=NULL){
        if(strcmp(cur->item,ch2)==0){
            cur->count++;
            return;
        }
        else if(strcmp(cur->item,ch2)>0){
            tmp=(Node)malloc(sizeof(struct node));
            strcpy(tmp->item,ch2);
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
    strcpy(tmp->item,ch2);
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
            ch2[i++]=ch;
            while(((ch=fgetc(fp))!=EOF)&&isalpha(ch)){
                if(isupper(ch)) ch=ch-'A'+'a';
                ch2[i++]=ch;
            }
            ch2[i]='\0';
            return 1;
        }
    }
    return 0;
}

