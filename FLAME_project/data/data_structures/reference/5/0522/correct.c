#include<stdio.h>
#include<stdlib.h>
struct node{
  int coe;
  int pow;
  struct node *link;
};
void exchange(struct node *p,struct node *q)
{
    int a0,n0;
    a0=p->coe;n0=p->pow;
    p->coe=q->coe;p->pow=q->pow;
    q->coe=a0;q->pow=n0;
}
void deletenode(struct node *list,struct node *p)
{
    struct node *r;
    if(p==list){
             list=list->link;
             free(p);
       }
      else{
             for(r=list; r->link!=p  &&  r->link!=NULL; r=r->link)
                    ;
             if(r->link!=NULL){
                   r->link=p->link;
                   free(p);
              }
      }
      return list;

}
int main()
{
    int a,n;
    char c;
    struct node *list,*p,*q,*x,*y,*head,*y0,*tmp=NULL;
    list=p=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
        q=(struct node*)malloc(sizeof (struct node));
        q->coe=a,q->pow=n,q->link=NULL;
        if(list==NULL)
            list=p=q;
        else{
            p->link=q;
            p=p->link;
        }
    }while(c!='\n');
    head=y=NULL;
    do{
        scanf("%d%d%c",&a,&n,&c);
        for(p=list;p!=NULL;p=p->link){
            x=(struct node*)malloc(sizeof (struct node));
            x->coe=a*(p->coe);
            x->pow=n+(p->pow);
            x->link=NULL;
            if(head==NULL)
                head=y=x;
            else{
                y->link=x;
                y=y->link;
            }
        }
    }while(c!='\n');
    for(x=head;x!=NULL;tmp=x,x=x->link){
        for(y=x->link;y!=NULL;y=y->link){
            if(x->pow<y->pow){
                exchange(x,y);
            }
            else if(x->pow==y->pow){
                x->coe=x->coe+y->coe;
                deletenode(head,y);
                }
        }
    }
    int flag=0;
    for(x=head;x!=NULL;x=x->link){
        printf("%d %d ",x->coe,x->pow);
    }
    return 0;
}



