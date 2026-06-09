#include <stdio.h>
#include <stdlib.h>

struct node{
    int xishu;
    int zhishu;
    struct node* next;
};

struct node* create(){
    struct node* headenode=(struct node*)malloc(sizeof(struct node));
    headenode->next=NULL;
    return headenode;
}

struct node* newnode(int xishu,int zhishu){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->xishu =xishu;
    newnode->zhishu =zhishu;
    newnode->next =NULL;
    return newnode;
}

void print(struct node* head){
    struct node* p=head->next ;
    while(p){
        
        printf("%d %d ",p->xishu ,p->zhishu );
        p=p->next ;
    }
    printf("\n");
    return;
}

void multiply(struct node* list1,struct node* list2,struct node* list3){
    struct node *p1=list1->next ,*p2=list2->next ,*p3=list3 ;
    while(p1){
        p3->next =newnode((p1->xishu )*(p2->xishu ),(p1->zhishu )+(p2->zhishu )); // @@ [Error: p2 is not reset for each p1; this loop only multiplies the first term of list2 with all terms of list1, but p2 is not advanced correctly and the initial p2 is used for all iterations, missing the rest of list2 terms]
        p1=p1->next ,p3=p3->next ;
    }
    p2=p2->next ;
    int a,b;
    struct node* frontp3;
    
    
    while(p2){
        p1=list1->next ;
        while(p1){
            p3=list3->next ,frontp3=list3;
        
            a=(p1->xishu )*(p2->xishu );
            b=(p1->zhishu )+(p2->zhishu );
            
            
             while(p3->zhishu >b&&p3->next ){ // @@ [Error: If p3->next is NULL and p3->zhishu > b, the loop exits but p3 points to the last node; subsequent logic may dereference NULL or incorrectly insert]
                p3=p3->next ,frontp3=frontp3->next ; 
            }
           
            if(p3->zhishu ==b){
                p3->xishu =p3->xishu +a;
            }
            if(p3->zhishu <b){
                struct node *p=newnode(a,b);
                frontp3->next=p;
                p->next=p3;
            }
            if(p3->next ==NULL){ // @@ [Error: This condition is always true when p3 is the last node, causing duplicate insertion even if the term already exists or was just inserted above]
                p3->next =newnode(a,b);
            } 
        p1=p1->next ;
         }  
         p2=p2->next ;
    }
        
    

    return ;
}

int main(){
    struct node* list1=create();
    struct node* list2=create();
    struct node* list3=create();
    struct node* p1=list1,*p2=list2;
    int a,b;
    while(scanf("%d%d",&a,&b)){

            p1->next=newnode(a,b);
            p1=p1->next ; 

        if(getchar()=='\n'){
            break;
        }
    }
    while(scanf("%d%d",&a,&b)){

            p2->next=newnode(a,b);
            p2=p2->next ; 

        if(getchar()=='\n'){
            break;
        }
    }
    multiply(list1,list2,list3);
    print(list3);

    return 0;
}