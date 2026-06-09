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
    
    do{ // @@ Loop does not check for EOF; should use while(scanf(...)!=EOF) to handle empty input correctly.
        scanf("%d%d%c",&a,&n,&c);
        q1=(struct Node *)malloc(sizeof(struct Node));
        p1=(struct Node *)malloc(sizeof(struct Node)); // @@ Redundant allocation, causes memory leak. Only one new node needed per term.
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
    
    do{ // @@ Loop does not check for EOF; should use while(scanf(...)!=EOF) to handle empty input correctly.
        scanf("%d%d%c",&a,&n,&c);
        for(p1=head1;p1!=NULL;p1=p1->next){
            a2=p1->coe*a;
            n2=p1->pow+n;
            q2=(struct Node *)malloc(sizeof(struct Node));
            p2=(struct Node *)malloc(sizeof(struct Node)); // @@ Redundant allocation, causes memory leak. Only one new node needed per product term.
            q2->coe=a2,q2->pow=n2,q2->next=NULL;
            if(head2==NULL){
                head2=p2=q2;
                
            }else{
                p0=p2;
                for(p2=head2;p2!=NULL;p0=p2,p2=p2->next){
                    if(q2->pow>p2->pow){
                        if(p2==head2){
                            q2->next=head2;
                            head2=q2;
                            break;
                        }else{
                            q2->next=p2;
                            p0->next=q2;
                            break;
                        }
                    }else if(q2->pow==p2->pow){
                        p2->coe+=q2->coe; // @@ Memory leak: q2 node not freed after merging.
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