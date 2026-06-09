#include<stdio.h>

int num[100];

int main()
{
    int a,b;
    int top=-1;
    
    do{
        scanf("%d",a); // @@ [scanf expects the address of the variable to store input, but 'a' is passed instead of '&a', leading to undefined behavior and likely crash]
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