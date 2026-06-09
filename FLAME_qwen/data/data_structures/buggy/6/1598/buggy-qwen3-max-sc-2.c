#include<stdio.h>

int num[100];

int main()
{
    int a,b;
    int top=-1;
    
    do{
        scanf("%d",a); // @@ [The variable 'a' is passed to scanf without the address-of operator (&). This causes undefined behavior because scanf expects a pointer to the variable to store the input. It should be '&a'.]
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