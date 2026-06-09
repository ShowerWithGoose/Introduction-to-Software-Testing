#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num[100][4];
int result[100];
int n;
int connect (int a,int b,int c,int d)
{
    if(a==c&&b==d)
        return 1;
    else
        return 0;
}

int max(int a[],int n)
{
    int i,flag=0,m;
    for(i=0;i<n;i++)
    {
        if(a[i]>flag)
        {
            flag=a[i];
            m=i;
        }

    }
    return m;
}

int digui(int a[n][4],int i,int flag1,int flag2,int n);

int main()
{
    int n,i,j,k,flag1,flag2,out;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        result[i]=0;
        scanf("%d%d%d%d",&num[i][0],&num[i][1],&num[i][2],&num[i][3]);
    }


    for(i=0;i<n;i++)
    {
        flag1=num[i][2];
        flag2=num[i][3];
        digui(num,i,flag1,flag2,n);
    }

    out=max(result,n);
   printf("%d %d %d",result[out]+1,num[out][0],num[out][1]);
return 0;

}

int digui(int a[n][4],int i,int flag1,int flag2,int n)
{

    int j=0;

    for(j=0;j<n;j++)
    {
        if(connect(flag1,flag2,num[j][0],num[j][1])==1)
            {
                result[i]=result[i]+1;
                flag1=num[j][2];
                flag2=num[j][3];
                digui(num,i,flag1,flag2,n);
                break;
            }
    }
}

