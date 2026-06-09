#include<stdio.h>
#include<string.h>
int *x,*y,tp,max;

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line* next;
};
struct line mem[105],*p;
void Input(int);


int main(){
    int n=0;
    scanf("%d",&n);
    Input(n);

    printf("%d %d %d\n",max,*x,*y);
    return 0;
}

void Input(int a){
    int i,j,k=1;
    for(i=0;i<a;i++){
        scanf("%d %d %d %d",&mem[i].x1,&mem[i].y1,&mem[i].x2,&mem[i].y2);
    }
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            if(mem[i].x2==mem[j].x1&&mem[i].y2==mem[j].y1)mem[i].next=&mem[j];
        }
    }
    for(i=0;i<a;i++){
        p=&mem[i];
        tp=1;
        while(p->next!=NULL){
            p=p->next;
            tp++;
        }
        if(tp>max){
            max=tp;
            x=&mem[i].x1;
            y=&mem[i].y1;
        }
    }
    return;
}

