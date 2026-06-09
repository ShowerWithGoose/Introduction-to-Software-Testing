#include <stdio.h>
void per(int a[],int t,int pre[],int n)
{
    if(t == n)
    {
        for(int i=1;i<=n;i++)
        {
        	if(a[i] == 0) pre[t] = i;
		}
		for(int i=1;i<=n;i++)
        {
        	printf("%d ",pre[i]);
		}
		printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            pre[t] = i;
            per(a,t+1,pre,n);
            a[i]=0;
        }
    }
    
}

int main()
{
    int a[20]={0},n,pre[20]={0};
    scanf("%d",&n);
    per(a,1,pre,n);
    return 0;
}



