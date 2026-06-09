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
                if(ptrt->x1==x2&&ptrt->y1==y2) // @@ The condition checks if the new segment's end (x2, y2) matches the chain's start (ptrt->x1, ptrt->y1). This implies prepending. However, the problem states x1 < x2 for segments, and continuous lines must have increasing x. Prepending a segment (which has smaller x) to a chain starting with larger x is valid logically for construction, but the length update logic below is flawed.
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
                        ptr1->len+=ptr->len; // @@ Logic Error: When merging two chains (flag==1 means we already attached to one chain, now attaching to another), simply adding lengths is incorrect if 'ptr' and 'ptr1' are part of the same logical structure or if the merge creates a cycle/double count. More critically, this block handles merging two existing chains via the new segment. The length should be ptr1->len + ptr->len + 1. But wait, ptr1->len was already incremented in the first if. This logic is deeply flawed for general chain merging.
                    }
                }
                while(ptrt->next!=NULL)
                {
                    ptrt=ptrt->next;
                }
                if(ptrt->x2==x1&&ptrt->y2==y1) // @@ Checks if new segment's start (x1, y1) matches chain's end. Appending.
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
                        ptr->len+=ptr1->len+1; // @@ Logic Error: Similar to above, merging logic is incorrect. If flag is 1, it means we already connected to one end. Now connecting to the other. This forms a single long chain. The total length should be sum of both parts + 1. The variable updates here are inconsistent and likely lead to wrong counts.
                    }
                }
                if(ptr->next==NULL)
                {
                    if(flag==0)
                {
                    PtrQ head=(PtrQ)malloc(sizeof(struct HN)); // @@ Variable Shadowing: This declares a NEW local variable 'head', hiding the outer 'head'. The new node is allocated and initialized, but it is NOT linked to the main list properly because 'ptr->next=head' links the current tail to this new local head, but the outer loop continues using the outer 'head'. Wait, ptr is traversing from outer head. If ptr->next is NULL, ptr is the last element in the list of chains. Linking ptr->next to the new local 'head' actually DOES link it to the main list structure pointed to by the outer head. HOWEVER, the variable name shadowing is confusing and risky. The real issue is that this new chain is created ONLY if flag==0 (not connected to any existing chain). This part is logically okay for creating a new disjoint chain, BUT the variable shadowing means subsequent accesses to 'head' inside this scope refer to the new node, not the list head. Since the block ends immediately after, it might work by accident, but it's bad practice. The critical error is likely in the length calculation or connection logic above.
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