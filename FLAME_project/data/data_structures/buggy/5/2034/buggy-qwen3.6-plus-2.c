#include <stdio.h>
#include <stdlib.h> 
struct Node{
    int coe;
    int pow;
    struct Node *next;
};
int main(){
    int a,n,a2,n2;
    char c;
    struct Node *head1=NULL,*head2=NULL,*p1,*q1=NULL,*p2,*q2=NULL,*p0=NULL,*p02=NULL;
    
    do{
        scanf("%d%d%c",&a,&n,&c);
        q1=(struct Node *)malloc(sizeof(struct Node));
        p1=(struct Node *)malloc(sizeof(struct Node)); // @@ Memory leak: allocated node p1 is never used or freed, and overwrites the pointer needed for traversal later if not handled carefully, but primarily it's wasted allocation.
        q1->coe=a,q1->pow=n,q1->next=NULL;
        if(head1==NULL){
            head1=p1=q1;
            p02=p1;
        }else{
            p02->next=q1;
            p1=q1;
            p02=p1;
        }
    }while(c!='\n');
    
    do{
        scanf("%d%d%c",&a,&n,&c);
        for(p1=head1;p1!=NULL;p1=p1->next){
            a2=p1->coe*a;
            n2=p1->pow+n;
            q2=(struct Node *)malloc(sizeof(struct Node));
            p2=(struct Node *)malloc(sizeof(struct Node)); // @@ Memory leak: allocated node p2 is immediately overwritten in the next line or loop initialization, causing loss of pointer and memory leak.
            q2->coe=a2,q2->pow=n2,q2->next=NULL;
            if(head2==NULL){
                head2=p2=q2;
                
            }else{
                p0=p2; // @@ Logic error: p2 is assigned to q2 above (head2=p2=q2), but here p0 is set to this new node. However, in the subsequent loop, p2 is reset to head2. The variable p0 is intended to track the previous node during insertion sort. If the list is not empty, p0 should be initialized properly before the inner loop. Here, assigning p0=p2 (which is head2) is okay only if we enter the loop, but the real issue is below.
                for(p2=head2;p2!=NULL;p0=p2,p2=p2->next){
                    if(q2->pow>p2->pow){
                        if(p2==head2){
                            q2->next=head2;
                            head2=q2;
                            break;
                        }else{
                            q2->next=p2;
                            p0->next=q2;
                        } // @@ Logic error: Missing break after inserting in the middle. Without break, the loop continues, potentially corrupting the list or causing infinite loops/unexpected behavior because p2 and p0 continue to advance while q2 has already been inserted.
                    }else if(q2->pow==p2->pow){
                        p2->coe+=q2->coe;
                        break;
                    }
                }
                if(p2==NULL){
                    p0->next=q2;
                }
            }
        }
        
    }while(c!='\n');
    for(p2=head2;p2!=NULL;p2=p2->next){
        printf("%d %d ",p2->coe,p2->pow);
    }
    return 0;
}