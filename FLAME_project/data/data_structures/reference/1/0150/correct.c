#include<stdio.h>
#include<math.h>

int main()
{
    int a,min,max,type;
    int arr[12];
    int tmp;
	scanf("%d",&a);
	min=a;
	max=0;
	for(int i=a;i>0;i--)
	{
		min+=(a-i)*pow(10,i);
	}
	for(int i=0;i<a;i++)
	{
		max+=(i+1)*pow(10,i);
	}
	for(int i=min;i<max+1;i++)
	{
		tmp=i;
		for(int j=a-1;j>=0;j--)
		{
			arr[j]=tmp%10;
			tmp/=10;
		}
		for(int j=0;j<a-1;j++)
		{
			for(int k=j+1;k<a;k++)
			{
				if(arr[j]==arr[k]||arr[k]>a||arr[j]>a||arr[k]==0)
				{
					type=1;
					break;
				}
			}
			if(type==1)
			{
				break;
			}
		}
		for(int j=0;j<a;j++)
		{
			if(type==1) break;
			printf("%d ",arr[j]);
		}
		if(type==0)
		{
			i+=8;
			printf("\n");
		}
		type=0;
	}
	return 0;
}

