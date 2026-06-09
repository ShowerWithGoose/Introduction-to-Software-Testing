#include<stdio.h>
#include<string.h>
int main()
{
    int stack[100]= {0},charge,a,flag=0;
    //printf("%d\n",stack[99]);
    scanf("%d ",&charge);
    while(charge!=-1)
    {
        //scanf("%d ",&charge);
        if(charge==1)
        {
            if(stack[99]==0)
            {
                scanf("%d ",&stack[flag]);
                flag++;
            }
            if(stack[99]!=0)
            {
                printf("error ");
                scanf("%d ",&stack[flag]);
                stack[flag]=0;
            }
        }
        if(charge==0)
        {
            if(stack[0]==0)
            {
                printf("error ");
            }
            if(stack[0]!=0)
            {
                printf("%d ",stack[flag-1]);
                stack[flag-1]=0;
                flag--;
            }
        }
        if(charge==-1)
        {
            break;
        }
        scanf("%d ",&charge);
    }
    //for(int i=0; i<1; i++)
    //{
    //printf("%d ",stack[0]);
    //}
    return 0;
}

