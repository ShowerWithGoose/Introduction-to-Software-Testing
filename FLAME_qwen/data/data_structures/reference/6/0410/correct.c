#include <stdio.h>

int main()
{
    int i = 0;
    int num[500];

    int n = 0;
    while((scanf("%d",&num[n]))!=EOF)
    {
        if(num[n]==-1)
        {
            break;
        }
        n++;
    }

    int homo[100];

    for(int j = 0;j<n,num[j]!=-1;j++)
    {
        if(num[j]==1)
        {
            homo[i]=num[j+1];
            i++;
        }
        if(num[j]==0)
        {
            if(i==0)
            {
                printf("error ");
            }
            if(i>0)
            {
                printf("%d ",homo[i-1]);
                homo[i-1] = 0;
                i--;
            }

        }
    }

    return 0;
}

