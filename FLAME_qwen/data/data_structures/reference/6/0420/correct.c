#include<stdio.h>

int stack[100];
int Top=-1;

int main()
{
    int i,j;
    int arr[1000];
    char s[6]="error";
    for(i=0;;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]==-1)
        {
            break;
        }
    }
    for(j=0;j<i+1;j++)
    {
        if(arr[j]==1)
        {
            if(Top==99)
            {
                printf("%s ",s);
            }
            else
            {
                stack[++Top]=arr[j+1];
            }
            j++;
        }
        if(arr[j]==0)
        {
            if(Top==-1)
            {
                printf("%s ",s);
            }
            else
            {
                printf("%d ",stack[Top--]);
            }
        }
        if(arr[j]==-1)
        {
            break;
        }
    }
    return 0;
}

