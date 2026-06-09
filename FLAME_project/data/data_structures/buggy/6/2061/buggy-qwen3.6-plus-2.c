#include <stdio.h>
int s[100];
int top=-1;
int main()
{
    int n,a;
    while(~(scanf("%d",&n))){
        if(n==1){
            scanf("%d",&a);
            if(top==99){
                printf("error ");
            }else{
                s[++top]=a;
            }
        }else{ // @@ The code fails to check if n is -1 (end of operations) or 0 (pop). It treats -1 as a pop operation, causing an extra "error" to be printed when the stack is empty after valid operations are done. The loop should break on -1.
            if(top==-1){
                printf("error ");
            }else{
                printf("%d ",s[top]);
                top--;
            }
        }
    }
    return 0;
}