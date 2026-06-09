#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
struct node{
	int num;
	int index;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
int n1=0,n2=0;
Nodeptr createList1()
{
    Nodeptr p,r,head=NULL;
    char c;             
    do{                     
        r=(Nodeptr)malloc(sizeof(Node));
        scanf("%d%d%c",&r->num,&r->index,&c);
        n1++;
        r->link=NULL;
        if (head==NULL)
            head=p=r;
        else{
            p->link=r;          
            p=p->link;
                }
        }while(c!='\n');
            return head;
    }
Nodeptr createList2(){
	Nodeptr p,r,head=NULL;
	char c;             
    do{                     
        r=(Nodeptr)malloc(sizeof(Node));
        scanf("%d%d%c",&r->num,&r->index,&c);
        n1++;
        r->link=NULL;
        if (head==NULL)
            head=p=r;
        else{
            p->link=r;          
            p=p->link;
                }
        }while(c!='\n');
    return head;
}
void bubble(Nodeptr head)
{
	int swap;
    if(head==NULL) return;
    Nodeptr end=NULL;
    while(end!=head)
    {
        Nodeptr p=head;
        Nodeptr plink=head->link;
        while(plink!=end)
        {
            if(p->index<plink->index)
            {
            	swap=p->index;
                p->index=plink->index;
                plink->index=swap;
                swap=p->num;
                p->num=plink->num;
                plink->num=swap;
            }
            p=p->link;
            plink=plink->link;
        }
        end=p;
    }
}
int main()
{
	Nodeptr p1=createList1();
	Nodeptr p2=createList2();
	Nodeptr head=NULL,p,r,head2=p2;
	int num0,index0;
	while(p1!=NULL){
		num0=p1->num;
		index0=p1->index;
		p2=head2;
		while(p2!=NULL){
			r=(Nodeptr)malloc(sizeof(Node));
			r->link=NULL;
			r->num=p2->num*num0;
			r->index=p2->index+index0;
			if (head==NULL)
            head=p=r;
        else{
            p->link=r;          
            p=p->link;
                }
			p2=p2->link;
		}
		p1=p1->link;
	}
	Nodeptr record=head;
    while(record!=NULL){
        r=record;
        p=record->link;
        while(p!=NULL){
            //若有相同的元素，则删除；否则两个指针继续向下走
            if(record->index==p->index){
            	record->num=record->num+p->num;
                r->link=p->link;
                free(p);
                p=r->link;
            }else{
                r=r->link;
                p=p->link;
            }
        }
        record=record->link;
    }
    bubble(head);
    p=head;
    while(p!=NULL){
    	printf("%d %d ",p->num,p->index);
    	p=p->link;
	}
}

