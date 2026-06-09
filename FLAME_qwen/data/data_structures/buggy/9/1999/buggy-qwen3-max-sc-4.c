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
                        else if(q->x==list[j]->x && q->y==list[j]->y){ @@ [This condition compares q with list[j], but it should compare with list[k]; also, this logic incorrectly tries to merge chains without proper validation and may cause cycles or incorrect linking]
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
    printf("%d %d %d",max,x,y); @@ [The program may output incorrect results due to flawed merging logic and potential memory/cycle issues, but the compilation error in the test environment is likely due to missing compiler (gcc not found), not code syntax. However, the code has logical errors that prevent correct execution. The primary logical flaw is in the chain merging logic which doesn't correctly handle all connection cases and may create invalid linked structures.]
}