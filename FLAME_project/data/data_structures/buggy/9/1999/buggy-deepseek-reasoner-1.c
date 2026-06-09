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
                q=(Nodeptr)malloc(sizeof(Node)); // @@ Creates a new node for the start point (x1,y1) even when that point already exists as the tail of another chain, causing duplicate nodes.
                q->x=x1;
                q->y=y1;
                q->link=list[j];
                list[j]=q; // @@ Overwrites the head of chain j with the new node, but the old head (the end point of the current segment) is still needed for correct connection.
                for(k=0;k<num;++k){
                    if(k==j) continue;
                    else{
                        p=list[k];
                        while(p->link!=NULL){
                            p=p->link;    
                        }
                        if(p->x==list[j]->x && p->y==list[j]->y){
                            p->link=list[j]; // @@ Links the tail of another chain to the new node, creating a duplicate point in the chain (two nodes with same coordinates).
                        }
                    }
                }
                break; // @@ Only processes the first matching head, missing the possibility that the current segment also matches a tail of another chain.
            }
            else{
                p=list[j];
                while(p->link!=NULL){
                    p=p->link;    
                }
                if(p->x==x1 && p->y==y1){
                    q=(Nodeptr)malloc(sizeof(Node)); // @@ Creates a new node for the end point (x2,y2) when that point already exists as the head of another chain, causing duplicate nodes.
                    q->x=x2;
                    q->y=y2;
                    p->link=q;
                    p=q;
                    q->link=NULL;
                    for(k=0;k<num;++k){
                        if(k==j) continue;
                        else if(q->x==list[k]->x && q->y==list[k]->y){
                            q->link=list[k]; // @@ Links the new node to the head of another chain, creating a duplicate point in the chain.
                        }
                    }
                    break; // @@ Only processes the first matching tail, missing the possibility that the current segment also matches a head of another chain.
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