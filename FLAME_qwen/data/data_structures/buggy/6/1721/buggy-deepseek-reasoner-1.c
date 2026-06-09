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
        scanf("%d",&opnum);
        if(opnum){ // @@ [Error: condition should be `if(opnum==1)` because push is indicated by 1, not any non-zero value. This incorrectly triggers for opnum==-1.]
            scanf("%d",&takenum); // @@ [Error: scanf is executed even when opnum is not 1 (e.g., -1), reading unintended input.]
            if(StackFull(inttop)){
                printf("error ");
            }
            else{
                intStack[++inttop]=takenum; // @@ [Error: Executed for opnum != 1 (e.g., -1), causing invalid push.]
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
        else if(opnum==-1) break; // @@ [Error: This branch is never reached because opnum==-1 is caught by the first `if(opnum)` block. The program never exits on -1.]
    }
    return 0;
}