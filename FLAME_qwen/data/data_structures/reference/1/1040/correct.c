#include <stdio.h>
int order[10],is_mark[10],n;
void recursion(int k)
{
	int i;
	if (k>n)
    {
		for (i=1;i<n;++i)
            printf("%d ",order[i]);
		printf ("%d\n",order[n]);
		return ;
	}
	else 
    {
		for (i=1;i<=n;++i)
        {
			if (!is_mark[i])
            {
				order[k]=i;is_mark[i]=1;
				recursion(k+1);
				order[k]=0;is_mark[i]=0;
			}
		}
	}
}
int main ()
{
	scanf ("%d",&n);
	recursion(1);
	return 0;	
}






