#include <stdio.h>
#include <stdlib.h>
int top=-1;
int Stack[200];
int main(){
    int op,tmp;
    while(scanf("%d",&op)&&op!=-1){
        if(op==1){
           scanf("%d",&tmp);
           if(top==99) {printf("error "); continue;}
           else{
               Stack[++top]=tmp;
           }
        }
        else{
            if(top==-1) {printf("error "); continue;}
           else{
                   printf("%d ",Stack[top]);
                   Stack[top]=0;
                   top--;
               }

        }
    }
}


