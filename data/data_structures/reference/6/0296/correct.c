#include <stdio.h>
#include <string.h>
int main()
{
    char er[]="error";
    int i=0;
    int ju[100]={0};
    int data[100]={0},num=0;
    int m=0,n=0;
    int da[100]={0};
    while(scanf("%d",&ju[i])==0||1||-1)
    {   
        if(ju[i]==1)
        {
        scanf(" %d ",&data[num]);
        num++;            
        }
        else
        getchar();            
        if(ju[i]==-1)
        {
        break;
        }
        i++;    
    }
    for(int j=0;j<i;j++)
    {
        if(ju[j]==0)
        {
            if(n==0)
            printf("%s ",er);
            else
            {
                printf("%d ",da[n]);
                n--;
            }
        }
        if(ju[j]==1)
        {
            n++;
            da[n]=data[m];
            m++;
        }
    }
    return 0;
}
