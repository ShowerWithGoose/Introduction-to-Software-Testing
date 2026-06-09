#include<stdio.h>
#include<malloc.h>
#define MAX 100
typedef struct line{
    int x1,y1,x2,y2,num;
    struct line* link;
}LIne,*LInklist;
int Get_Line(LInklist L[]){
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        L[i]=(LInklist)malloc(sizeof(LIne));    
        scanf("%d %d %d %d",&L[i]->x1,&L[i]->y1,&L[i]->x2,&L[i]->y2);
        L[i]->num=0;
    }
    return n;
}
LInklist Create_Link(LInklist a){
    LInklist p;
    p=(LInklist)malloc(sizeof(LIne));
    p->x1=a->x1;
    p->x1=a->y1;
    p->x2=a->x2;
    p->y2=a->y2;
    return p;
}
void Connect(LInklist L[],int n){
    int i,j,k,s;
    LInklist p;
    for(i=0;i<n;i++){
        p=L[i];
        for(j=0;j<n-1;j++){
            s=0;
            for(k=0;k<n;k++){
                if(L[k]->x1==p->x2&&L[k]->y1==p->y2){
                    p->link=Create_Link(L[k]);
                    p=p->link;
                    (L[i]->num)++;
                    s=1;
                    break;
                }
            }
            if(s==0) break;
        }
    }
}
int main(){
    LInklist List[MAX],p;
    int n;
    int i;
    n=Get_Line(List);
    Connect(List,n);
    p=List[0];
    for(i=1;i<n;i++)
        if(List[i]->num>p->num)
            p=List[i];
    printf("%d %d %d",p->num+1,p->x1,p->y1);
}


