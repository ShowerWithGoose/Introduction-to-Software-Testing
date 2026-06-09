#include<stdio.h>
typedef struct line{
int x1;
int y1;
int x2;
int y2;
struct line* next;
};

int length(struct line a){
if(a.next==NULL)
    return 1;
else
    return (1+length(*a.next));
}

int main(){
int num;
scanf("%d",&num);
struct line a[100]={0,0,0,0,NULL};
for(int i=0;i<num;i++){
    scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);//数据输入
    for(int j=0;j<i;j++){
        if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2)//前面输入的线段在后端
            a[i].next=&a[j];
        else if(a[j].x2==a[i].x1&&a[j].y2==a[i].y1)//前面的线段在前端
            a[j].next=&a[i];
    }//拼接阶段
}
int lon[100]={0};
for(int i=0;i<num;i++)
    lon[i]=length(a[i]);
int i=-1,max=0;
    for(int i=0;i<num;i++){
        if(lon[i]>max){
            max=lon[i];
            i=i;
        }
    }
printf("%d %d %d",lon[i],a[i].x1,a[i].y1);
return 0;
}

