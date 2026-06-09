#include<stdio.h>
struct mul{
    int num;
    int pow;
    struct mul* link;
};
typedef struct mul Node;
typedef struct mul* Nodeptr;
Nodeptr creatList(Nodeptr list);
Nodeptr multi(Nodeptr q,Nodeptr p);
Nodeptr search(Nodeptr list,Nodeptr r);
void printLIST(Nodeptr r);
void freelist(Nodeptr list);
int main(){
    Nodeptr list1=NULL,list2=NULL,result=NULL;
    list1=creatList(list1);
    list2=creatList(list2);
    result = multi(list1,list2);
    printLIST(result);
    freelist(list1);
    freelist(list2);
    return 0;
}

Nodeptr creatList(Nodeptr list){
    Nodeptr p,q;
    char c='\0';
    while(c!='\n'){
        p = (Nodeptr)malloc(sizeof(Node));
        scanf("%d%d",&p->num,&p->pow);
        if(list==NULL)
            list = p;
        else
            q->link = p;
        p->link = NULL;
        q = p;
        scanf("%c",&c);
    }
    return list;
}

Nodeptr multi(Nodeptr q,Nodeptr p){
    Nodeptr r,list=NULL,listp=p;
    int i=1;
    while(q!=NULL){
        while(p!=NULL){
            r = (Nodeptr)malloc(sizeof(Node));
            r->num = p->num * q->num;
            r->pow = p->pow + q->pow;
            r->link = NULL;
            if(list==NULL){
                list = r;
            }else
                list = search(list,r);
            p = p->link;
        }
        p = listp;
        q = q->link;

    }
    return list;
}

Nodeptr search(Nodeptr list,Nodeptr r){
    Nodeptr q=list,p=list;
    //q在前面，p在后面；
    while(q!=NULL){
        if(q->pow == r->pow){
            q->num += r->num;
            free(r);
            break;
        }
        if(q->pow < r->pow){
            if(q==list){
                r->link = list;
                list = r;
                break;
            }else if(p->pow > r->pow){
                r->link = q;
                p->link = r;
                break;
            }
        }

        if(q!=list){
            p = q;
            q = q->link;
        }else q = q->link;

    }

    if(q==NULL){
        p->link = r;
    }

    return list;
}

void printLIST(Nodeptr r){
    Nodeptr q=r;
    while(r!=NULL){
        printf("%d %d ",r->num,r->pow);
        q=r;
        r=r->link;
        free(q);
    }

}

void freelist(Nodeptr list){
    Nodeptr q=list;
    while(list!=NULL){
        q = list;
        list=list->link;
        free(q);
    }
}


