#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



void f(int a,int t,int flag [50],int left[50])
{
    for (int i = 1; i <= a; i++)
    {
        
        if ((left[i]!=1)&&t<=a)
        {
            flag[t]=i;
            left[i]=1;
            f(a,t+1,flag,left);
            left[i]=0;
        }

        if (t>a&&i==1)
        {
            i+=a;/*optimized*/
            for (int k = 1; k <=a; k++)
            {
                printf("%d ",flag[k]);
            }
            printf("\n");
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int a,flag[50]={0},left[50]={0};
    scanf("%d",&a);
    f(a,1,flag,left);

    return 0;
}



