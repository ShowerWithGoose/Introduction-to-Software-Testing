#include<stdio.h>
int main()
{
    int stack[101],i=0;
    int op,x;
    while(1){
        scanf("%d",&op);
        if(op==-1)return 0;
        if(op==1){
            scanf("%d",&x);
            if(i==100)
                printf("error ");
            else{
                i++;
                stack[i]=x;
            }
        }
        else
            if(i==0)
                printf("error ");
            else{
                printf("%d ",stack[i]);
                i--;
            }
    }
}



