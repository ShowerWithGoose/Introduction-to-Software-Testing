#include <stdio.h>
#include <stdlib.h>
typedef struct a{
    int data[100];
    int top;
}Sqstack;
int main(){
    int tmp, num;
    Sqstack S;
    scanf("%d",&tmp);
    S.top=-1;
    while(tmp!=-1){
        if(tmp==1){
            scanf("%d",&num);
            if(S.top==99){
                printf("error ");
            }
            else {
                S.top++;
                S.data[S.top]=num;
            }
        }
        else if(tmp==0){
            if(S.top==-1){
                printf("error ");
            }
            else {
                printf("%d ",S.data[S.top]);
                S.top--;
            }
        }
        scanf("%d",&tmp);
    }
    return 0;
}
