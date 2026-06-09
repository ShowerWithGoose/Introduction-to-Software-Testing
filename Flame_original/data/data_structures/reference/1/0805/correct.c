#include<stdio.h>
#include<string.h>
int a[15]={0},b[15]={0};
int j=1,n;
void pailie(int k)
{
	int i;
    for (i=1;i<=n;i++)
    {
        if (b[i]==0)
        {
            b[i]=1;
            a[j]=i;
            j++;
            if (k==n)
            {
            	int i1;
            	for (i1=1;i1<=n;i1++)
    				printf("%d ",a[i1]);
    			printf("\n");
			}
            else pailie(k+1);
            j--;
            b[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    pailie(1);
}



