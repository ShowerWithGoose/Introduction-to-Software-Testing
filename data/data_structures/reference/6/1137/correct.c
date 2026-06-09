#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int top = -1;
int isFull()
{
    return top == 99;
}
int isEmpty()
{
    return top == -1;
}

int main()
{
    int s[100]={0},a;
    int i=0,j=0,temp=0;
    while (scanf("%d",&a)!=EOF)
    {
        if (a==1)
        {
            scanf("%d", &temp);
            if (isFull())
                printf("error ");
            else
                s[top+1] = temp;
                top++;   
        }
        if(a==0)
        {
            if (isEmpty())
                printf("error ");
            else
            {
                printf("%d ", s[top]);
                s[top] = 0;
                top--;
            }
        }
        
    }
    
    return 0;
}

