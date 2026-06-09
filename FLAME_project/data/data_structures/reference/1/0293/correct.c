#include<stdio.h>
#define MAX 10//日后如有需要再行更改
int num;
int arr[MAX] = {},state[MAX] = {};//第0列表示第i+1行填进去的数，第1列表示第i+1行是否可用
int *ptr = arr,*stt = state;//这里用了两个指向数组的指针
void fullarray(int step,int n){
    int i;
    if(step == n + 1){
        for (i = 1; i < n; i++) {
            printf("%d ",*(ptr+i-1));
        }
        printf("%d\n",*(ptr+i-1));
        return;
    }
    for (i = 1;i <= n;i++){
        if(*(stt+i-1) == 0){//0为可用，1为不可用
            *(ptr+step-1)= i;
            *(stt+i-1) = 1;
            fullarray(step+1,num);
            *(stt+i-1) = 0;
        }
    }
    return;
}
int main(){
    scanf("%d",&num);
    fullarray(1,num);
}


