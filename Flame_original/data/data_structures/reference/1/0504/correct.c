#include<stdio.h>
void selection(int k);
int bag[20]={0};
int n;
int point[20]={0};
int main()
{

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        bag[i]=1;
    }
    selection(n);
    return 0;
}
void selection(int k){

    if(k==0)
    {
        for(int i=n;i>=1;i--)
            printf("%d ",point[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(bag[i]==1)
        {
            point[k]=i;
            bag[i]=0;

            selection(k-1);

            bag[i]=1;

        }


    }

}

