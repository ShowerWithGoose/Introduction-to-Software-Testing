#include<stdio.h>
int z[100];
int main()
{
    int cz,i=0,j,k;
    while(scanf("%d",&cz))
    {
        if(cz==-1) break;
        else if(cz==1)
        {
            if(i==100)
            {
                scanf("%d",&j);
                printf("error ");
                continue;
            }
            else
            {
                i++;
                scanf("%d",&j);
                z[i]=j;
            }
        }
        else if(cz==0)
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",z[i]);
                i--;
            }
        }
    }
}

