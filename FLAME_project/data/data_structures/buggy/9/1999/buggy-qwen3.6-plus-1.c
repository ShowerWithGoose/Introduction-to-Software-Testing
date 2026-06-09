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
                            p->link=list[j]; // @@ [Logical Error: This merges two separate chains incorrectly. If chain K ends at the start of chain J, it appends the entire chain J to K. However, chain J was just modified (prepended). This creates a structure where multiple heads might point into the same chain or cycles, and crucially, it doesn't update the 'head' of the merged chain in the list array correctly for future lookups or length calculations starting from other nodes. More specifically, it fails to consolidate the lists into a single canonical head, leading to double counting or incorrect chain traversal.]
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
                        else if(q->x==list[j]->x && q->y==list[j]->y){ // @@ [Logical Error: The condition compares the new node q with list[j] (the current chain being processed in the outer loop), but it should compare with list[k] (the other chain being checked for connection). It should be q->x == list[k]->x && q->y == list[k]->y.]
                            q->link=list[j]; // @@ [Logical Error: Due to the previous error, this links to the wrong list. Even if the condition were correct (checking against list[k]), it should link to list[k], not list[j].]
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