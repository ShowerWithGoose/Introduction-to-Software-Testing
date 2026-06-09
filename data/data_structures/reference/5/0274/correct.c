#include<stdio.h>
#include<stdlib.h>
struct node{
    int coefficient;
    int index;
    struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr list1=NULL,list2=NULL;
int main(){
    int x,y,flag=0,a,b;
    char c='0';
    Nodeptr p1=list1,p=list2,q1,q;
    while(flag!=2){
        scanf("%d%d%c",&x,&y,&c);
        if(!flag){
            q1=(Nodeptr)malloc(sizeof(Node));
            q1->coefficient=x;
            q1->index=y;
            q1->link=NULL;
            if(list1==NULL)
                list1=p1=q1;
            else
                p1->link=q1;
            p1=q1;
        }else{
            for(p1=list1;p1!=NULL;p1=p1->link){
                a=x*p1->coefficient,b=y+p1->index;
                if(list2==NULL){
                    q=(Nodeptr)malloc(sizeof(Node));
                    q->coefficient=a;
                    q->index=b;
                    q->link=NULL;
                    list2=q;
                }else
                for(p=list2;p!=NULL;p=p->link){
                    if(b==p->index){
                        p->coefficient+=a;
                        break;
                    }else if(p->link==NULL){
                        q=(Nodeptr)malloc(sizeof(Node));
                        q->coefficient=a;
                        q->index=b;
                        q->link=NULL;
                        p->link=q;
                        break;
                    }else if(b<p->index&&b>p->link->index){
                        q=(Nodeptr)malloc(sizeof(Node));
                        q->coefficient=a;
                        q->index=b;
                        q->link=p->link;
                        p->link=q;
                        break;
                    }
                }
            }
        }
        if(c=='\n') flag++;
    }
    for(p=list2;p!=NULL;p=p->link){
        printf("%d %d",p->coefficient,p->index);
        if(p->link!=NULL) printf(" ");
    }
    return 0;
}
