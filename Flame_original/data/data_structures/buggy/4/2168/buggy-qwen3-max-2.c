#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct words
{
    char s[50];
    int count;
    struct words * next;
};
struct words *q,*first=NULL,*head;

char * transform(char * read){
    for(int i=0;read[i]!='\0';i++){
        if(read[i]>='A'&&read[i]<='Z'){
            read[i]=read[i]-('A'-'a');
        }
        else if(read[i]>='a'&&read[i]<='z'){

        }
        else{
            for(int j=i;read[j]!='\0';j++){
                read[j]=read[j+1];
            }
            i--;
        }
    }
    return read;
}

struct words * proc (struct words * head,struct words * first,char* read){
    struct words *q=first,*p=head;//p-->q
    while(q!=NULL){
        if(strcmp(read,q->s)==0){
            (q->count)++;
            return head;
        }
        else if(strcmp(read,p->s)>0&&strcmp(read,q->s)<0){
            struct words *temp;
            temp=(struct words *)malloc(sizeof(struct words));
            temp->count=0;
            strcpy(temp->s,read);
            (temp->count)++;
            p->next=temp;
            temp->next=q;
            return head;            
        }
        else{
            q=q->next;
            p=p->next;
        }
    }
    q=(struct words *)malloc(sizeof(struct words));
    q->next=NULL;
    p->next=q;
    strcpy(q->s,read);
    q->count=0;
    q->count ++;
    return head;
}

int main(){
    FILE *in;
    in= fopen("article.txt","r");
    if (NULL == in){
        printf("Failed to open the file !\n");
        exit(0);
    }
    char read[50];
    char *pread=read;
    head=(struct words *)malloc(sizeof(struct words));
    head->count=0;
    head->s[0]='\0';
    /*first=(struct words *)malloc(sizeof(struct words));
    first->count=0;
    first->s[0]='\0';
    first->next=NULL;*/
    head->next=first;
    while(fscanf(in ,"%s",read)!=EOF){
        pread=transform(read);
        //printf("%s\n",pread);
        if(*pread!='\0')
            head=proc(head,first,pread);
        first=head->next;
        q=first;
        /*while(q!=NULL){
            printf("%s %d\n",q->s,q->count);
            q=q->next;
        }
        printf("-------------------------\n");*/
    }
    q=first;
    while(q!=NULL){
        printf("%s %d\n",q->s,q->count);
        q=q->next;
    }
    q=head;
    struct words *qfree=q;
    while(q!=NULL){
        q=q->next;
        free(qfree);
        qfree=q;
    }
    fclose(in);
    return 0;
}