#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[100]={0};
int len = -1;
void pushin(int arr[100],int num)
{
    if (len == 99)
    {
        printf("error ");
    }
    else
    {
        arr[len + 1] = num;
        len++;
    }
    return;
}
void popout(int arr[100])
{
    if (len==-1)
    {
        printf("error ");
    }
    else
    {
        printf("%d ", arr[len]);
        len--;
    }
    return;
}
int main()
{
    int s;
    int num;
    while (1)
    {
        scanf("%d", &s);
        if (s == -1)
        {
            break;
        }
        else if(s==1)
        {
            scanf("%d", &num);
            pushin(arr, num);
           
        }
        else if (s == 0)
        {
            popout(arr);
            
        }

    }
    return 0;
}
