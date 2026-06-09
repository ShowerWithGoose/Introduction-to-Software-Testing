#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char c[30];
    int cnt;
    struct node* next;
}*head,*p;
void checkWord(struct node* headnode,char w[30]){
    struct node *pm=headnode,*qm=NULL;
    int is_put=0;
    // printf("%s\n",w);
    while(pm!=NULL){
        // printf("%s\n",pm->c);
        
        if(strcmp(w,pm->c)==-1){
            // printf("chekchcek\n");
            // printf("chahcachahchachschahcas %s %s %s\n",w,pm->c,headnode->c);
            if(pm==headnode){
                
                struct node* u=(struct node*)malloc(sizeof(struct node));
                strcpy(u->c,w);
                u->cnt=1;
                u->next=head;
                head=u;
            }else{
                struct node* u=(struct node*)malloc(sizeof(struct node));
                strcpy(u->c,w);
                u->cnt=1;
                u->next=pm;
                qm->next=u;
            }
            is_put=1;
            break;
            
        }else if(strcmp(pm->c,w)==0){
            
            pm->cnt++;
            is_put=1;
            break;
        
        }else{
            // printf("check1\n");
            qm=pm;
            pm=pm->next;
            // printf("check2\n");
        }
        
    }
    // printf("isout?????\n");
    if(!is_put){
        
        struct node* u=(struct node*)malloc(sizeof(struct node));
        strcpy(u->c,w);
        u->cnt=1;
        qm->next=u;
        u->next=NULL;
        
    }
    return;
}
void printNode(struct node* headnode){
    struct node* pm=headnode;
    while(pm!=NULL){
        printf("%s %d\n",pm->c,pm->cnt);
        pm=pm->next;
    }
}
char c,word[100]; // @@ [The variable 'c' should be declared as 'int' to properly compare with EOF, which is an integer value outside the range of char. Using 'char' may cause infinite loops or incorrect EOF detection on some systems.]
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    int cntWord=0;
    head=NULL;
    while ((c=fgetc(in))!=EOF){ // @@ [fgetc() returns an 'int', but 'c' is declared as 'char'. This can cause issues when comparing with EOF because EOF is typically -1, which may not be representable in a signed char or may collide with valid byte values in unsigned char.]
        // printf("%c",c);
        if(c>='A'&&c<='Z') {
            word[cntWord++]=c-'A'+'a';
        }else if(c>='a'&&c<='z'){
            word[cntWord++]=c;
        }else {
            if(cntWord==0) continue;
            word[cntWord]='\0';
            // printf("%s\n",word);
            if(head==NULL){
                struct node* u=(struct node*)malloc(sizeof(struct node));
                strcpy(u->c,word);
                u->cnt=1;
                u->next=NULL;
                head=u;
                p=u;

            }else checkWord(head,word);
            // printf("Hi\n");
            cntWord=0;
        }
    }
    if(head==NULL){
            struct node* u=(struct node*)malloc(sizeof(struct node));
            strcpy(u->c,word);
            u->cnt=1;
            u->next=NULL;
            head=u;
            p=u;
    }else if(cntWord!=0)checkWord(head,word);
    // printf("fuck\n");
    printNode(head);
    return 0;
}