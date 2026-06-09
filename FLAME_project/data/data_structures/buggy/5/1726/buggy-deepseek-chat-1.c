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
        p3->next =newnode((p1->xishu )*(p2->xishu ),(p1->zhishu )+(p2->zhishu ));
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
            
            
             while(p3->zhishu >b&&p3->next ){
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
            if(p3->next ==NULL){
                p3->next =newnode(a,b); // @@ [Error: This condition is always true after the while loop if p3 is the last node, but it incorrectly adds a new node even when the exponent b is greater than p3->zhishu (which would have been handled by the previous if) or when b is less than p3->zhishu (which would cause duplicate insertion). The logic should only add a new node if b is less than p3->zhishu and p3 is the last node, but the previous if(p3->zhishu < b) already handles insertion before p3. This line causes extra nodes to be appended incorrectly, leading to duplicate terms in the output.]
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