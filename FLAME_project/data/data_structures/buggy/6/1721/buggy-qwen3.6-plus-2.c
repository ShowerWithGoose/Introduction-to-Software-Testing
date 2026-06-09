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
        scanf("%d",&opnum); // @@ The logic fails to distinguish between the operand for push (1) and the operation code itself correctly in all cases, but specifically here, if opnum is 1, it reads the next number. However, the condition `if(opnum)` is true for 1, -1, and any other non-zero number. If opnum is -1, it enters the first block, tries to scanf another number, which might not exist or be wrong, leading to infinite loop or wrong behavior. But the main issue for TLE is likely that when opnum is -1, it doesn't break immediately inside the loop structure properly if the logic falls through or waits for more input. Actually, looking closely: if opnum is -1, `if(opnum)` is true. It executes `scanf("%d",&takenum)`. If there is no more input, scanf waits or fails. If it succeeds, it pushes. Then loop continues. Next scanf reads -1 again? No, the input is `1 567 0 -1`. 
        // Trace:
        // 1. scanf opnum = 1. if(1) is true. scanf takenum = 567. Push 567.
        // 2. Loop continues. scanf opnum = 0. if(0) is false. else if(0==0) is true. Pop 567. Print "567 ".
        // 3. Loop continues. scanf opnum = -1. if(-1) is true. scanf takenum... waits for input! There is no more input. This causes the program to hang (Time Limit Exceeded).
        // The fix is to check for -1 before checking for non-zero, or restructure the if-else chain.
        
        if(opnum){
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