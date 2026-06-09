#include <stdio.h>
int flag[11],n,r[11];
void func(int num,int wait)
{
    int i,j;
    if(wait==0) 
    {
        for(j=0;j<n;j++) 
            printf("%d ",r[j]);
        printf("\n");
    }   
    else 
    {
        for(i=0;i<n;i++)
        {
            if(flag[i]!=1) 
            {
                flag[i]=1;
                r[num]=i+1;
                func(num+1,wait-1);
                flag[i]=0;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    func(0,n);
    return 0;
}


