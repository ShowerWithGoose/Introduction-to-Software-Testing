/*#include<stdio.h>
#include<string.h>
int n;
void fun(int a[],int flag[],int i,int ans[])
{
    int j,k;
    if(i==n)
    {
        for(k=0;k<n;k++)
            printf("%d",ans[k]);
        printf("\n");
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(flag[j]==0)
            {
                ans[i]=a[j];
                flag[j]=1;
                fun(a,flag,i+1,ans);
                flag[j]=0;
            }
        }
    }
}
int main()
{
    int i;
    int flag[20];
    int a[20],ans[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        flag[i]=0;
    }
    fun(a,flag,0,ans);
    return 0;
}*/

#include<stdio.h>
int a[15],flag[15],b[15],n;
void f(int a[],int flag[],int b[],int x)
{
	int i,j,k;
	if(x==n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	else
	{
		for(j=0;j<n;j++)
		{
			if(flag[j]==0)
			{
				b[x]=a[j];
				flag[j]=1;
				f(a,flag,b,x+1);
				flag[j]=0;
			}
			
		}
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	f(a,flag,b,0);
	return 0;
}




