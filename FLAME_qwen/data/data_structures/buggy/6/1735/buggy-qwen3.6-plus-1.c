#include<stdio.h>
int Input_Queue(int *queue,int queue_Num,int num);
int Output_Queue(int *queue,int queue_Num);
int main(){
    int queue[100];
    int queue_Num=0,op,Num;
    while((scanf(" %d",&op))!=EOF){ // @@ [scanf returns the number of successfully matched items; comparing to EOF may cause an infinite loop if non-integer input is encountered. Using == 1 is safer for robust input handling.]
        if(op==-1)break;
        else if(op==1){
            scanf(" %d",&Num); // @@ [Should ideally verify the return value of scanf to ensure Num was successfully read before using it in the push operation.]
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