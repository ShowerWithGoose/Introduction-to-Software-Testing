#include <stdio.h>
int stack[100],a,k=0;
int main()
{
	scanf("%d",&a);
	while(a!=-1)
	{
		if(a!=1&&a!=0){
			if(k<100){
				stack[k]=a;
				k++;
			}
			else 
			printf("error ");
	    }
		else if(a==0&&k!=0)
		{
			printf("%d ",stack[k-1]);
			stack[k-1]=0;
			k--;
		}
		else if(a==0&&k==0)
		{
			printf("error ");
		}
		scanf("%d",&a);
	}
	return 0;
}

