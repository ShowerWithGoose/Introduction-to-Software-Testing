#include<stdio.h>
#include<stdlib.h>

int stack[150];
int head;
int tail;
int main()
{
    int opt,num;
    while(1)
    {
        scanf("%d", &opt);
        if(opt==-1) break;

        if(opt==1){
            scanf("%d",&num);
            if(tail>=100)
            printf("error ");
            else
            stack[tail++]=num;    
        }
        else {
            if(!tail) printf("error ");
            else{
                tail--;
                printf("%d ",stack[tail]);
            }
        }
    }
    return 0;
}
