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
        }else{ // @@ The else block incorrectly catches -1 and treats it as a pop operation. It should explicitly check for n==0 and break when n==-1 to terminate the operations.
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