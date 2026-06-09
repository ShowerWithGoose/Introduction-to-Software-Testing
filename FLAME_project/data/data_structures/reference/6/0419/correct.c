#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int arr[100],judge,i=0;//设置一个栈和判断操作
    while(1)
    {
        scanf("%d",&judge);//判断操作
        if(judge==1)
        {
            if(i>=100)
                printf("error ");
            else  scanf("%d",&arr[i++]);//读入数据
        }
        else if(judge==0)
        {
            if(i<=0)
                printf("error ");
            else {printf("%d ",arr[i-1]);i--;}
        }
        else break;
    }
    return 0;
}



