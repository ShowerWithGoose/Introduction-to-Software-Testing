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
                if(ptrt->x1==x2&&ptrt->y1==y2) // @@ [Logic Error: This condition checks if the new segment's END (x2,y2) matches the chain's START (ptrt->x1, ptrt->y1). This implies the new segment comes BEFORE the current chain. However, the code below sets temp->next = ptrt, which is correct for prepending, but the coordinate check is reversed relative to standard segment direction (Start->End). More critically, it fails to handle the case where segments form a long chain correctly because it only checks the head of the list in `ptr->right`. It does not traverse the whole chain to find connections at the tail or head properly in all cases, leading to incorrect merging or counting.]
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
                        ptr1->len+=ptr->len; // @@ [Logic Error: Incorrect length calculation when merging two chains. If `flag` is already 1, it means we found a connection earlier. Adding `ptr->len` to `ptr1->len` double counts or incorrectly aggregates lengths because `ptr1` and `ptr` might represent overlapping or distinct parts of the structure incorrectly managed by this simple linked list of chains approach.]


                    }
                }
                while(ptrt->next!=NULL)
                {
                    ptrt=ptrt->next;
                }
                if(ptrt->x2==x1&&ptrt->y2==y1) // @@ [Logic Error: This condition checks if the new segment's START (x1,y1) matches the chain's TAIL (ptrt->x2, ptrt->y2). This implies the new segment comes AFTER the current chain. The code appends `temp` to `ptrt->next`. This part is logically consistent for appending, but combined with the previous check and the `flag` logic, it fails to correctly maintain the integrity of the chain length and structure, especially when multiple segments connect.]
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
                        ptr->len+=ptr1->len+1; // @@ [Logic Error: Incorrect length calculation. Similar to the previous error, this arithmetic does not correctly reflect the number of segments in the merged chain.]

                    }
                }
                if(ptr->next==NULL)
                {
                    if(flag==0)
                {
                    PtrQ head=(PtrQ)malloc(sizeof(struct HN)); // @@ [Variable Shadowing Error: This declares a NEW local variable `head` instead of using the outer `head` or creating a new node in the list properly linked to the existing structure. This new node is lost after the block ends, and the new segment is effectively discarded or not added to the main list of chains correctly.]
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