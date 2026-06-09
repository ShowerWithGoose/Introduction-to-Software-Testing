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
                            p->link=list[j];
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
                        else if(q->x==list[j]->x && q->y==list[j]->y){
                            q->link=list[j];
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
    printf("%d %d %d",max,x,y); // @@ [The variable 'x' and 'y' may be used uninitialized if no continuous line segment is found (e.g., when n=0 or all segments are isolated and num=0). Also, 'max' is initialized to 0, but if there are no segments, the output should reflect that. However, more critically, in the case where a new segment is added (j == num), the code sets list[j] = p = q (first node), then appends a second node. But when computing length later, it counts links, so a single segment (two nodes) yields lenth=1, which is correct. However, the real issue is that the inner loops attempt to merge chains by checking endpoints, but the logic for merging across different chains is flawed and may cause infinite loops or incorrect linking. Additionally, in the 'else if' inside the k-loop: "else if(q->x==list[j]->x && q->y==list[j]->y)" uses 'j' instead of 'k', which is a critical typo causing wrong comparisons.]
}