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
        if(opnum){ @@ [This condition treats any non-zero opnum as a push operation, but according to the problem, only opnum == 1 should trigger a push. Thus, if opnum is e.g., 2, it incorrectly assumes it's a push and reads another integer.]
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