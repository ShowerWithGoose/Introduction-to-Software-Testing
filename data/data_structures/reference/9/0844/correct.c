#include<stdio.h>
#include<stdlib.h>
typedef struct Point *P;
struct Point{
    int x,y;
    P next;
};
P p[105];
int n;
int getlen(P x){
    int len=0;
    while(x->next!=NULL){
        len++;
        x=x->next;
    }
    return len;
}
int cnt;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<105;i++){
        p[i]=malloc(sizeof(struct Point));
        p[i]->next=NULL;
    }
    for(int i=1;i<=n;i++){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        P a=NULL,b=NULL;
        for(int j=1;j<=cnt;j++){
            if(p[j]->x==x1&&p[j]->y==y1){
                a=p[j];
                continue;
            }
            if(p[j]->x==x2&&p[j]->y==y2){
                b=p[j];
                continue;
            }
        }
        if(a==NULL){
            a=p[++cnt];
            a->x=x1,a->y=y1;
        }
        if(b==NULL){
            b=p[++cnt];
            b->x=x2,b->y=y2;
        }
        a->next=b;
    }

    P ans;
    int maxlen=-1;
    for(int i=1;i<=cnt;i++){
        int len=getlen(p[i]);
        if(len>maxlen){
            ans=p[i];
            maxlen=len;
        }
    }
    printf("%d %d %d",maxlen,ans->x,ans->y);
    return 0;
}
