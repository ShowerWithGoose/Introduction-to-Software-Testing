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
        p1=(struct Node *)malloc(sizeof(struct Node)); // @@ Memory leak: p1 is allocated but immediately overwritten in the if/else block, causing lost memory. While not the primary cause of TLE, it's incorrect. More importantly, the logic for building list 1 is flawed compared to reference but functionally similar enough for small inputs. However, the main issue is below.
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
            p2=(struct Node *)malloc(sizeof(struct Node)); // @@ Memory leak: p2 is allocated here but immediately overwritten by the loop initialization `p2=head2` below. This allocates unused memory repeatedly.
            q2->coe=a2,q2->pow=n2,q2->next=NULL;
            if(head2==NULL){
                head2=p2=q2;
                
            }else{
                p0=p2; // @@ Logic Error: p0 is set to the newly allocated (and leaked) p2 node, not the previous node in the list. When entering the loop, p0 should be initialized properly relative to the traversal. In the reference code, p0 is updated inside the loop `for(...; ...; p0=p2, p2=p2->next)`. Here, p0 is set before the loop to a garbage/unrelated node.
                for(p2=head2;p2!=NULL;p0=p2,p2=p2->next){
                    if(q2->pow>p2->pow){
                        if(p2==head2){
                            q2->next=head2;
                            head2=q2;
                            break;
                        }else{
                            q2->next=p2;
                            p0->next=q2; // @@ Potential Crash/Logic Error: If the loop breaks here, p0 points to the node before p2. This part is logically okay IF p0 was tracked correctly. However, see the next point.
                            break; // @@ Missing Break: The reference code has a break here. Without this break, the loop continues even after insertion, which might lead to incorrect behavior or infinite loops if not handled carefully, but primarily it's inefficient. Wait, looking at reference: `else { q2->next = p2; p0->next = q2; break;}`. The buggy code lacks this break.
                        }
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