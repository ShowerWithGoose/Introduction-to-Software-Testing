#include <stdio.h>
#define MAXAMOUNT 99
int isFull(int cnt){
    return cnt == MAXAMOUNT;
}

int isEmpty(int cnt){
    return cnt == -1;
}
int main(){
    int stack[105];
    int operate, cnt = -1;
    scanf("%d", &operate);
    while (operate != -1)
    {   
        if (operate == 1 && !isFull(cnt))
            scanf("%d", &stack[++cnt]);
        else if(!operate && !isEmpty(cnt))
            printf("%d ", stack[cnt--]);
        else if((!operate && isEmpty(cnt)) ||(operate == 1 && isFull(cnt))){
            printf("error ");
        }
        scanf("%d", &operate);
    }
}
