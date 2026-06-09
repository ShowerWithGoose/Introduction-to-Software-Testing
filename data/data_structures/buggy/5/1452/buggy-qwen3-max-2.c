#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct elem{
    int a;
    int n;
}Elemtype;
typedef struct node{
    Elemtype data;
    struct node *link;
}Listnode;
Listnode *create(Elemtype item);
void insert(Listnode *list,Elemtype item);
Listnode *destroy(Listnode *list);
void print(Listnode *list);
int main()
{
    Elemtype item,item_mul;
    char judge;
    Listnode *list_a,*list_ans;
    item.a=0;
    item.n=0;
    list_a=create(item);
    list_ans=create(item);
    do{
        scanf("%d%d%c",&item.a,&item.n,&judge);
        insert(list_a,item);
    }while(judge!='\n');
    Listnode *pp;
    do{
        scanf("%d%d%c",&item.a,&item.n,&judge);
        pp=list_a;
        do{
            pp=pp->link;
            item_mul.a=(item.a)*(pp->data.a);
            item_mul.n=(item.n)+(pp->data.n);
            insert(list_ans,item_mul);
        }while(pp->link!=NULL);
    }while(judge!='\n');
    print(list_ans);
    destroy(list_a);
    destroy(list_ans);
    return 0;
}
Listnode *create(Elemtype item){
    Listnode *list;
    list=(Listnode *)malloc(sizeof(Listnode));
    list->data=item;
    list->link=NULL;
    return list;
}
void insert(Listnode *list,Elemtype item){
    Listnode *p_before,*p_after,*p_insert;
    for(p_before=list,p_after=list->link;p_after!=NULL;p_before=p_after,p_after=p_after->link){
        if(p_after->data.n<=item.n){
            break;
        }
    }
    if(p_after==NULL){
        p_insert=create(item);
        p_before->link=p_insert;
    }else{
        if(p_after->data.n==item.n){
            p_after->data.a+=item.a;
        }else{
            p_insert=create(item);
            p_insert->link=p_after;
            p_before->link=p_insert;
        }
    }
}
Listnode *destroy(Listnode *list){
    Listnode *p=list;
    while(list!=NULL){
        p=list->link;
        free(list);
        list=p;
    }
    return NULL;
}
void print(Listnode *list){
    Listnode *p=list;
    while(list!=NULL){
        p=list->link;
        printf("%d %d",p->data.a,p->data.n); // @@ [Accessing p->data when p may be NULL; also skips the first real node due to initial dummy node and prints nothing if list has only dummy node]
        list=p;
        if(list!=NULL){
            printf(" ");
        }
    }
}