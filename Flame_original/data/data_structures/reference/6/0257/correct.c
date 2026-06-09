#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int a[250];
	int b[250];
	int i=0,j,k=0,c;
    while(scanf("%d",&a[i])!=-1)
    {
    	i++;
	}
	int len=i;
	for(j=0;j<len;j++)
	{
		if(a[j]==1&&k<100)
		{
			b[k]=a[j+1];
			j=j+1;
			k=k+1;
		}
		else if(a[j]==0&&k>0)
		{
			printf("%d ",b[k-1]);
			k=k-1;
		}
		else if(k==0&&a[j]==0)
		{
				printf("error "); 
		}
		else if(k==100&&a[j]==1)
		{
			j=j+1;
			printf("error ");
		}
	}
        
}



