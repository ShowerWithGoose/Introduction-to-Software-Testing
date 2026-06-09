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
        }else{
            if(top==-1){ // @@ The condition should check for n==0 (pop operation) before handling other cases, because the input can contain values other than 1, 0, and -1 (e.g., the pushed integer 567). The current else branch treats any non-1 value as a pop, causing the pushed value 567 to be incorrectly processed as a pop operation, leading to an "error" output.
                printf("error ");
            }else{
                printf("%d ",s[top]);
                top--;
            }
        }
    }
    return 0;
}