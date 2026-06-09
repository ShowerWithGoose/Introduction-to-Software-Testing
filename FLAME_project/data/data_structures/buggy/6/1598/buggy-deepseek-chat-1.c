#include<stdio.h>

int num[100];

int main()
{
    int a,b;
    int top=-1;
    
    do{
        scanf("%d",a); // @@ [Missing address-of operator (&) before 'a'. Should be scanf("%d", &a); This causes undefined behavior and likely a runtime error.]
        if(a==1){
            scanf("%d",&b);
            if(top==99){
                printf("error ");
            }
            else{
                num[++top]=b;
            }
            
        }
        else if(a==0){
            if(top==-1){
                printf("error ");
            }
            else{
                printf("%d ",num[top--]);
            }
        }
        
    }while(a!=-1);
    
    
    return 0;
}