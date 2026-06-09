#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
typedef struct {
    int a;
    int b;
    struct Node *next;
}Node;

Node *head_link;
void insert(int a,int b){

    if(head_link->next==NULL){
        Node *link=(Node*)malloc(sizeof(Node));
        link->a=a;
        link->b=b;
        link->next=NULL;
        (head_link->next)=link;
        return;
    }
    Node *link_hold=head_link;
    Node *link=link_hold->next;
    while(link_hold!=NULL){
        link=link_hold->next;
        if(link==NULL){
            Node *p=(Node*)malloc(sizeof(Node));
            p->a=a;
            p->b=b;
            p->next=link_hold->next;
            link_hold->next=p;
            return;
        }
        if(link->b<b){
            Node *p=(Node*)malloc(sizeof(Node));
            p->a=a;
            p->b=b;
            p->next=link_hold->next;
            link_hold->next=p;
            return;
        }
        if(link->b==b){
            link->a+=a;
            return;
        }
        if(link->b>b){
            
        }
        
        link_hold=link;
    }

}
void put(){
    Node *p=head_link->next;
    while(p!=NULL){
        if(p->a!=0) {
            printf("%d %d",p->a,p->b);
            putchar(' ');
        }
        p=p->next;
    }
}

int main(){
    Node x1[512]={},x2[512]={};
    head_link=(Node*)malloc(sizeof(Node));
    head_link->next=NULL;
    int n1=0,n2=0;
    int i=0;
    scanf("%d%d",&x1[i].a,&x1[i].b); // @@ This line reads the first term of the first polynomial but leaves the newline. The following loop then reads the second polynomial's data as part of the first polynomial, corrupting the input.
    char c;
    for(i=1;;i++){
    scanf("%d%d",&x1[i].a,&x1[i].b); // @@ This reads the next term, but for a single-term polynomial it incorrectly reads the next line (second polynomial's term) because the newline after the first term caused the loop to continue.
    
    c=getchar();
    if(c=='\n'){
        break;
    }    
    }
    //printf("OK1");
    n1=i; // @@ n1 is set to 1 (the index of the erroneously read term), causing later loops to include the second polynomial's term as part of the first polynomial.
    for(i=0;;i++){
        scanf("%d%d",&x2[i].a,&x2[i].b); // @@ Since the second polynomial's term was already consumed, stdin is now at EOF. This scanf never returns successfully, and the loop never breaks, causing a Time Limit Exceeded.
        c=getchar();
    if(c=='\n'){
        break;
    }    }
    //printf("OK2");
    //∂¡ÕÍ¡À
    n2=i; // @@ Due to the infinite loop, this line is never reached, but even if it were, i would be undefined.
int j;
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            insert(x1[i].a*x2[j].a,x1[i].b+x2[j].b);
        }
    }
    put();
    return 0;
}