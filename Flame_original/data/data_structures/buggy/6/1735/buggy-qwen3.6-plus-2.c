#include<stdio.h>
int Input_Queue(int *queue,int queue_Num,int num); // @@ Parameter name 'num' in prototype differs from 'Num' in definition. While syntactically valid in C, it is better practice to match names or omit them in prototypes to avoid confusion.
int Output_Queue(int *queue,int queue_Num);
int main(){
    int queue[100];
    int queue_Num=0,op,Num;
    while((scanf(" %d",&op))!=EOF){ // @@ scanf returns the number of items successfully read. Comparing with EOF works for end-of-file but may cause infinite loops on invalid input. It should ideally check for == 1. The reported compilation error is environmental (gcc not found), but this line is a common source of runtime/logic issues.
        if(op==-1)break;
        else if(op==1){
            scanf(" %d",&Num);
            queue_Num=Input_Queue(queue,queue_Num,Num);
        }
        else if(op==0)queue_Num=Output_Queue(queue,queue_Num);
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