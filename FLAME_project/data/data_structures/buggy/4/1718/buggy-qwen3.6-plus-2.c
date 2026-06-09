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
            free(p); // @@ Memory leak: p was allocated but not used/freed when word already exists
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
        free(p); // @@ Memory leak: p was allocated but not used/freed when word already exists at the last node
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
                tmp[tmplong++]=tolower(sent[i]); // @@ Logic error: Only the first character was converted to lowercase in the original code, but all characters in a word need to be lowercased to match "C" with "c" etc.
            }else if(tmplong>0){
                    // Removed incorrect manual uppercase conversion since we now use tolower above
                    tmp[tmplong]='\0';
                    head=insert(head,tmp);
                    for(int j=0;j<tmplong;j++){
                        tmp[j]='\0';
                    }
                    tmplong=0;
            }
        }
        // @@ Logic error: If the file ends with a word (no trailing non-alpha character), the last word is never processed because the else-if block only triggers on non-alpha chars. Need to handle end-of-line.
        if(tmplong > 0) {
             tmp[tmplong]='\0';
             head=insert(head,tmp);
             tmplong=0;
        }
    }
    fclose(in);
    while(head!=NULL){
        printf("%s %d\n",head->word,head->time);
        head=head->next;
    }
    return 0;
}