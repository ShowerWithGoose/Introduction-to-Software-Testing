#include<stdio.h>
int main(void)
{
    int num[100]={};
    int n=0,length=-1;
    while(n!=-1)
    {
        scanf("%d",&n);
        if(n==1)
        {
            if(length<100)
                scanf("%d",&num[++length]);
            else printf("error ");
        }   
        else if(n==0){
            if(length<=-1)
                printf("error ");
            else
                printf("%d ",num[length--]);
        }
    }
}
