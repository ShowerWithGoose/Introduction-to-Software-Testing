#include<stdio.h>
int a[12];
int b[12];
int main()
{
	int n,i,k=0,status=0,p,q,c,d,e,f;
	scanf("%d",&n);
	if(n==1)
	{printf("1"); 
	return 0;
	}
	for(i=1;i<=n;i++)
	a[i]=i;
	for(i=1;i<=n;i++)
            printf("%d ",a[i]);
    printf("\n");
    status=1;
	while(!(k==1&&status==-1))
	{
		if(status==1)
		{
			a[n-1]^=a[n];
			a[n]^=a[n-1];
			a[n-1]^=a[n];
            for(i=n-1;i>=1;i--)
            {
            	if(a[i]>a[i-1])
            	{
            		k=i;
            		break;
				}
            	
			}
            status=-1;
            for(i=1;i<=n;i++)
            printf("%d ",a[i]);
            printf("\n");
		}
		else
		{
			i=k;
			while(a[i]>a[k-1])
			i++;
			q=i;
			p=q-1;
			b[k-1]=a[p];
			d=n-q+1;
			for(i=0;i<d;i++)
			b[k+i]=a[n-i];
			c=k+n-q+1;
			b[c]=a[k-1];
			e=p-k;
			c++;
			f=p-1;
			for(i=0;i<e;i++)
			b[c+i]=a[f-i];
			status=1;
			for(i=k-1;i<=n;i++)
			a[i]=b[i];
			for(i=1;i<=n;i++)
            printf("%d ",a[i]);
            printf("\n");
		}
	}
	return 0;
}



