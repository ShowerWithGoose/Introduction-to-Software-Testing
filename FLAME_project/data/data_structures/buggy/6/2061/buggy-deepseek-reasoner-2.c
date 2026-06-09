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
        }else{ // @@ This else branch handles any input that is not 1, including -1. According to the problem, -1 signals the end of operations and should not be treated as a pop operation. Because there is no check for n==-1, the program incorrectly treats -1 as a pop, causing an erroneous "error " print after a valid pop.
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