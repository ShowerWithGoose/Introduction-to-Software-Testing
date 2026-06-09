#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define M 100
int StackFull(int a){
    return a==99; // @@ Error: The stack capacity is M=100, so the stack is full when top equals 99 (0-indexed), but the reference program uses top==99 for full check. However, the problem states maximum capacity is 100, and the reference program initializes top=0 and checks top==99 for full, meaning valid indices are 1-99 (1-indexed). In this code, inttop starts at -1 (0-indexed), so full should be when inttop == M-1 == 99. This condition is correct for 0-indexed stack with capacity 100, but the reference program uses 1-indexed stack with top starting at 0 and full at top==99. The logic mismatch may cause errors in behavior, but the main issue is that the code does not handle the case when opnum is 1 (push) correctly because the condition `if(opnum)` treats any non-zero as push, but opnum could be -1 which is also non-zero, causing incorrect behavior.
}
int StackEmpty(int a){
    return a==-1;
}
int intStack[M]={0},inttop=-1,opnum,takenum;
int main(){
    while(1){
        scanf("%d",&opnum);
        if(opnum){ // @@ Error: This condition treats any non-zero value as a push operation, but opnum could be -1 (end of operations) which is also non-zero. This causes the program to attempt to read a push value when opnum is -1, leading to incorrect input parsing and potential errors.
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