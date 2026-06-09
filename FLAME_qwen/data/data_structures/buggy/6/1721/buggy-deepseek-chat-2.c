#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define M 100
int StackFull(int a){
    return a==99; // @@ The stack full condition is incorrect. With top starting at -1, the stack is full when top == M-1 (99), but the function should check if a == M-1, not a==99. However, the main issue is that the push operation logic is flawed: when opnum is non-zero (including 1), it always reads a value, but the problem specifies that only op==1 indicates a push. The code treats any non-zero opnum as a push, which is wrong. Also, the condition for push should check if opnum == 1, not just if it's non-zero.
}
int StackEmpty(int a){
    return a==-1;
}
int intStack[M]={0},inttop=-1,opnum,takenum;
int main(){
    while(1){
        scanf("%d",&opnum);
        if(opnum){ // @@ This condition is incorrect. It treats any non-zero value (including -1) as a push operation. The problem specifies that only 1 indicates a push, 0 indicates pop, and -1 indicates end. This should be if(opnum == 1) instead.
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