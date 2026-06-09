#include <stdio.h>
void perm(int n,int s,int a[],int b[])
{
	int i;
	if(s==n+1) 
	{
	    for(i=1;i<=n;i++) printf("%d ",a[i]);
	    printf("\n");
	    return;
    }
    for(i=1;i<=n;i++)
    {
    	if(b[i]==0)
    	{
    		a[s]=i;
    		b[i]=1;
    		perm(n,s+1,a,b);
    		b[i]=0;
		}
	}
}
int main()
{
	int a[15]={0},b[15]={0},n;
	scanf("%d",&n);
	perm(n,1,a,b);
	return 0;
}

