#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
        int xishu;
        int zhishu;
        struct node* link;
    }node;
typedef node* Nodeptr;
Nodeptr createList()  
{
    node* list=malloc(sizeof(node));
    list->link=NULL;
    return list;
}
void print_polynome(Nodeptr p)
{
    p = p->link;
    while(p != NULL){
        printf("%d %d ",p->xishu,p->zhishu);
        p = p->link;
    }
}
void polynome_addition(Nodeptr  p1, Nodeptr p2)
{
    node*p = p1;
    p1 = p1->link;
    p2 = p2->link;
    while(p1!=NULL&&p2!=NULL){
        if(p1->zhishu>p2->zhishu){
            p->link = p1;
            p1 = p1->link;
        }else if(p1->zhishu<p2->zhishu){
            p->link = p2;
            p2 = p2->link;
        }else {
            p1->xishu+=p2->xishu;
            p->link = p1;
            p1 = p1->link;
            p2 = p2->link;
        }
        p = p->link;        
    }
    if(p1==NULL)p->link = p2;
    else if(p2 == NULL)p->link = p1;
    else p->link = NULL;
}


Nodeptr  poly_muti(Nodeptr  p1, node*p2)

{
    Nodeptr result = createList();
    node*final = result;
    node*p = p1->link;
    while(p1!=NULL){ // @@ [Infinite loop: p1 never advances; should use 'p' which is correctly initialized to p1->link]
        final->link = malloc(sizeof(node));
        final = final->link;
        final->xishu = p1->xishu *p2->xishu;
        final->zhishu = p1->zhishu + p2->zhishu;
        p=p->link;
        final->link = NULL;
    }   
    return result;
}


int main()
{
    Nodeptr Nodeptr1=createList();
    Nodeptr Nodeptr2=createList();
    node*p1=Nodeptr1;
    node*p2=Nodeptr2;
    int a,b;
    while(1){
        scanf("%d%d",&a,&b);
        p1->link = malloc(sizeof(node));
        p1=p1->link;
        p1->xishu=a;
        p1->zhishu=b;
        p1->link=NULL;
        if(getchar()=='\n') break;
    }
    while(scanf("%d %d",&a,&b)!=EOF){ // @@ [Incorrect input termination: mixing scanf with getchar may leave newline in buffer, causing premature exit or infinite loop; also, second polynomial input may not read correctly due to leftover '\n']
        p2->link = malloc(sizeof(node));
        p2=p2->link;
        p2->xishu=a;
        p2->zhishu=b;
        p2->link=NULL;
        if(getchar()=='\n') break;
    }
    
    Nodeptr ans = createList();
node*p = Nodeptr2->link;
while(p!=NULL){
     polynome_addition(ans,poly_muti(Nodeptr1,p)); // @@ [poly_muti returns a new list, but polynome_addition merges two sorted lists; however, the result of poly_muti is unsorted and not combined properly across multiple terms, leading to incorrect merging and memory issues]
     p = p->link;
}
print_polynome(ans);
return 0;
 }