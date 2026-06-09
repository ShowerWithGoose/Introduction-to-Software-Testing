#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct words{
    char word[20];
    int time;
    struct words *next;
};
typedef struct words *list;
list insert(list head,char *tmp){
    list r=head;
    list p=(list)malloc(sizeof(struct words));
    strcpy(p->word,tmp);
    p->time=1;
    p->next=NULL;
    if(head==NULL){
        return p;
    }
    if(strcmp(head->word,p->word)>0){
        p->next=head;
        return p;
    }
    while(r->next!=NULL){
        int op=strcmp(r->word,p->word);
        if(op==0){
            r->time++;
            return head;
        }else if(op<0){
            r=r->next;
        }else{
            list check=head;
            while(check->next!=r){
                check=check->next;
            }
            p->next=r;
            check->next=p;
            return head;
        }
    }
    if(strcmp(r->word,p->word)==0){
        r->time++;
        return head;
    }else if(strcmp(r->word,p->word)<0){
        r->next=p;
        return head;
    }else{
        list check=head;
        while(check->next!=r){
            check=check->next;
        }
        p->next=r;
        check->next=p;
        return head;
    }
}
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char sent[1024];
    list head=NULL;
    while(fgets(sent,1024,in)!=NULL){
        char tmp[20];
        int tmplong=0;
        for(int i=0;sent[i]!='\0';i++){
            if((sent[i]<='z'&&sent[i]>='a')||(sent[i]>='A'&&sent[i]<='Z')){
                tmp[tmplong++]=sent[i];
            }else if(tmplong>0){
                    if(tmp[0]>='A'&&tmp[0]<='Z'){ // @@ [Only the first character is converted to lowercase; the entire word should be lowercased (e.g., by using tolower() for each character) to correctly merge case variations.]
                        tmp[0]+='a'-'A';
                    }
                    tmp[tmplong]='\0';
                    head=insert(head,tmp);
                    for(int j=0;j<tmplong;j++){
                        tmp[j]='\0';
                    }
                    tmplong=0;
            }
        }
    }
    fclose(in);
    while(head!=NULL){
        printf("%s %d\n",head->word,head->time);
        head=head->next;
    }
    return 0;
}