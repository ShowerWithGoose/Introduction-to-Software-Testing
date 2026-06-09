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
    struct words *q=first,*p=head;//p-->q @@ The logic assumes 'head' is a dummy node and 'first' is the actual first data node, but initialization in main sets head->next to NULL (since first is NULL). If the list is empty, this function will crash or behave incorrectly because p (head) has an empty string and q is NULL. More critically, the insertion logic relies on p and q being adjacent valid nodes with data.
    while(q!=NULL){
        if(strcmp(read,q->s)==0){
            (q->count)++;
            return head;
        }
        else if(strcmp(read,p->s)>0&&strcmp(read,q->s)<0){ @@ This condition fails if the new word should be inserted before the very first node (if head was not a dummy) or if the list structure isn't maintained as expected. However, the major issue is that 'head' is treated as a dummy node with an empty string. strcmp(read, "") > 0 is always true for non-empty read. So it tries to insert between head (dummy) and first node. This part is logically okay IF head is always a dummy. But look at the initialization in main.
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
    // If we reach here, the word is larger than all existing words (or list was empty)
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
    head->next=first; // @@ first is NULL here. So head->next is NULL. The list effectively starts with a dummy head node pointing to nothing.
    while(fscanf(in ,"%s",read)!=EOF){
        pread=transform(read);
        //printf("%s\n",pread);
        if(*pread!='\0')
            head=proc(head,first,pread); // @@ On the first call, first is NULL. Inside proc: q=first (NULL), p=head. The while(q!=NULL) loop doesn't execute. It goes to the end: mallocs new node q, p->next=q. This correctly adds the first node after head.
        first=head->next; // @@ Updates first to point to the actual first data node.
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