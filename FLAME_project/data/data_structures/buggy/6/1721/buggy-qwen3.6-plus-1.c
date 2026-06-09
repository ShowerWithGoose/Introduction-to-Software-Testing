#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define M 100
int StackFull(int a){
    return a==99;
}
int StackEmpty(int a){
    return a==-1;
}
int intStack[M]={0},inttop=-1,opnum,takenum;
int main(){
    while(1){
        scanf("%d",&opnum); // @@ The logic for handling '1' (push) is incorrect. It assumes that if opnum is non-zero, it is a push operation requiring a second integer. However, -1 is also non-zero. When opnum is -1, the code enters the first if block, attempts to scanf another integer for 'takenum', which causes it to wait for input indefinitely or read incorrectly, leading to Time Limit Exceeded or wrong behavior. The condition should explicitly check for 1.
        if(opnum){ // @@ This condition catches both 1 and -1 (and any other non-zero). It should be `if (opnum == 1)` to correctly distinguish push operations from the termination signal -1.
            scanf("%d",&takenum);
            if(StackFull(inttop)){
                printf("error ");
            }
            else{
                intStack[++inttop]=takenum;
            }
        }
        else if(opnum==0){
            if(StackEmpty(inttop)){
                printf("error ");
            }
            else{
                printf("%d ",intStack[inttop--]);
            }
        }
        else if(opnum==-1) break;
    }
    return 0;
}