#include <stdio.h>
int a[11]={1,2,3,4,5,6,7,8,9,10};
int main()  
{  
    int i,n,s,t,j;
    scanf("%d",&n);
	for(i=0;i<n;i++)
	    printf("%d ",a[i]);
	printf("\n");
	for(i=n-1;i>0;i--)
	{
		if(a[i]>a[i-1])
	    {
			s=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j]>a[i-1]&&a[j]<a[j-1])
				s=j;
			}
			t=a[i-1];
			a[i-1]=a[s];
			a[s]=t;
		
		for(j=0;j<(n-i)/2;j++)
		{
			t=a[i+j];
			a[i+j]=a[n-1-j];
			a[n-1-j]=t;
		}
		for(i=0;i<n;i++)
	        printf("%d ",a[i]);
	    printf("\n");
	    }
	}
    return 0;   
} 




