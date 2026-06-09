#include<stdio.h>
#include<stdlib.h>
typedef struct N *PtrN;
struct N
{
    int x1;
    int y1;
    int x2;
    int y2;
    PtrN next;

};

typedef struct HN * PtrQ;
struct HN
{
    PtrN right;
    PtrQ next;
    int len;

};


int main()
{
    PtrQ head=(PtrQ)malloc(sizeof(struct HN));
    head->next=NULL;
    head->right=NULL;
    head->len=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x1,y1;
        int x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        PtrN temp=(PtrN)malloc(sizeof(struct N));
        temp->x1=x1;
        temp->y1=y1;
        temp->x2=x2;
        temp->y2=y2;
        temp->next=NULL;
        if(head->right==NULL)
        {
            head->right=temp;
            head->len++;
        }
        else
        {
            PtrQ ptr=head;
            PtrQ ptr1=NULL;
            int flag=0;
            while(ptr!=NULL)
            {
                PtrN ptrt=ptr->right;
                if(ptrt->x1==x2&&ptrt->y1==y2)
                {
                    if(flag==0)
                    {
                        temp->next=ptrt;
                        ptr->right=temp;
                        ptr->len++;
                        flag=1;
                        ptr1=ptr;


                    }
                    else{
                        temp->next=ptr->right;
                        ptr1->len+=ptr->len;


                    }
                }
                while(ptrt->next!=NULL)
                {
                    ptrt=ptrt->next;
                }
                if(ptrt->x2==x1&&ptrt->y2==y1)
                {
                    if(flag==0)
                    {
                        ptrt->next=temp;
                        ptr->len++;
                        ptr1=ptr;
                        flag=1;
                    }
                    else{
                        ptrt->next=temp;
                        ptr->len+=ptr1->len+1;

                    }
                }
                if(ptr->next==NULL)
                {
                    if(flag==0)
                {
                    PtrQ head=(PtrQ)malloc(sizeof(struct HN)); // @@ [Variable 'head' is redeclared in inner scope, shadowing the outer 'head'. This creates a new local variable instead of updating the list structure. Should use a different variable name like 'newNode'.]
                    head->next=NULL;
                    head->right=NULL;
                    head->len=1;
                    head->right=temp;
                    ptr->next=head;
                    break;
                    
                }

                }
               
                ptr=ptr->next;
            }
             
               

                
            
            
        }


    }
    PtrQ x=head;
    PtrQ y=head;
    while(x!=NULL)
    {
        if(x->len>=y->len)
        {
            y=x;
        }
        x=x->next;
    }
    printf("%d %d %d",y->len,y->right->x1,y->right->y1);
    return 0;

}