#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node{
     int x;
     int y;
     struct node *link;
 };
 typedef struct node Node;
 typedef struct node *Nodeptr;
int main(){
    int n,i,j,x1,k,x2,y1,y2,num=0,lenth=0,max=lenth,x,y;
    Nodeptr p,q,list[100]={NULL};
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(j=0;j<num;++j){
            if(list[j]->x==x2 && list[j]->y==y2){
                q=(Nodeptr)malloc(sizeof(Node));
                q->x=x1;
                q->y=y1;
                q->link=list[j];
                list[j]=q;
                for(k=0;k<num;++k){
                    if(k==j) continue;
                    else{
                        p=list[k];
                        while(p->link!=NULL){
                            p=p->link;    
                        }
                        if(p->x==list[j]->x && p->y==list[j]->y){
                            p->link=list[j]; // @@ This merges list j into list k but does not remove list j from the array; list j remains as a separate entry, leading to double counting and incorrect length/s starting point.
                        }
                    }
                }
                break;
            }
            else{
                p=list[j];
                while(p->link!=NULL){
                    p=p->link;    
                }
                if(p->x==x1 && p->y==y1){
                    q=(Nodeptr)malloc(sizeof(Node));
                    q->x=x2;
                    q->y=y2;
                    p->link=q;
                    p=q;
                    q->link=NULL;
                    for(k=0;k<num;++k){
                        if(k==j) continue;
                        else if(q->x==list[j]->x && q->y==list[j]->y){ // @@ Should compare with list[k] instead of list[j] to check if the new tail matches the head of another list; this condition is always false because list[j] is the head of the same list.
                            q->link=list[j]; // @@ Links the new tail to the head of the same list (list[j]) instead of linking to another list (list[k]); this does not perform the intended merge.
                        }
                    }
                    break;
                }
            } 
        }
        if(j==num){
                q=(Nodeptr)malloc(sizeof(Node));
                q->x=x1;
                q->y=y1;
                list[j]=p=q;
                q=(Nodeptr)malloc(sizeof(Node));
                q->x=x2;
                q->y=y2;
                p->link=q;
                p=q;
                q->link=NULL;
                num++;
        }
    }
    for(i=0;i<num;++i){
        lenth=0;
        p=list[i];
        while(p->link!=NULL){
            p=p->link;
            lenth++;
        }
        if(lenth>max){
            max=lenth;
            x=list[i]->x;
            y=list[i]->y;
        }
    }
    printf("%d %d %d",max,x,y);
}