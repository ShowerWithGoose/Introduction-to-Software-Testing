#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,j,cs;
	int max=0,bg;
	int temp,temp2;
	int temp3,temp4;
	int sum=1;
	int a[100],b[100],c[100],d[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	for (i = 0; i < n-1;i++) {               
		for (j = 0; j < n-1 - i;j++) {     
			if (a[j] >a[j + 1]) {
				
				temp = a[j];temp2=b[j];
				temp3=c[j];temp4=d[j];
				a[j] = a[j + 1];b[j]=b[j+1];
				c[j]=c[j+1];d[j]=d[j+1];
				a[j + 1] = temp;b[j+1]=temp2;
				c[j+1]=temp3;d[j+1]=temp4;
			}
			}
			}

	int k;
	for(i=0;i<n;i++){ 
		sum=1;
	    k=i;
		for(j=i+1;j<n;j++){ 
			if(c[k]==a[j]&&d[k]==b[j])
			{   
			  sum=sum+1;
			  k=j;
			 
			}
			 if(j==n-1)
			  {
			  	if(max<sum)
				{
				
			  	bg=i;
			  	max=sum;
			  	
			  	}
				  break;
			  }
	}		
}
printf("%d %d %d",max,a[bg],b[bg]);
}


