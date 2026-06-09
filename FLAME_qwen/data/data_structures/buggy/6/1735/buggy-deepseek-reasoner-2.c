#include<stdio.h>
int Input_Queue(int *queue,int queue_Num,int Num);
int Output_Queue(int *queue,int queue_Num);
int main(){
    int queue[100];
    int queue_Num=0,op,Num;
    while((scanf(" %d",&op))!=EOF){
        if(op==-1)break;
        else if(op==1){
            scanf(" %d",&Num);
            queue_Num=Input_Queue(queue,queue_Num,Num); // @@ 缺少函数原型声明可能导致C99标准下编译错误
        }
        else if(op==0)queue_Num=Output_Queue(queue,queue_Num); // @@ 同上
    }
    return 0;
}
int Input_Queue(int *queue,int queue_Num,int Num){
    if(queue_Num==100){
        printf("error ");
        return queue_Num;
    }
    else{
        queue[queue_Num]=Num;
        queue_Num++;
        return queue_Num;
    }
}
int Output_Queue(int *queue,int queue_Num){
    if(queue_Num==0){
        printf("error ");
        return queue_Num;
    }
    else{
        queue_Num--;
        printf("%d ",queue[queue_Num]);
        return queue_Num;
    }
}