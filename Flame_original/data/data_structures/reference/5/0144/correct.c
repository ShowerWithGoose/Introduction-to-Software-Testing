#include<stdio.h>
#include<string.h>
int a[1000][1000]={0};
//int ans[1000000]= {0};
int main()
{
	int in1[1000]= {0},in2[1000]= {0};
	int num1[500]= {0},num2[500]= {0},index1[500]= {0},index2[500]= {0};
	char flag1,flag2;
	int i,j,k,n1,n2,a1,a2,flag,m,temp1,temp2;

	//读入多项式1
	for(i=0; flag1!='\n'; i++)
	{
		scanf("%d",&in1[i]);
		flag1=getchar();
	}
	n1=i;

	//读入多项式2
	for(i=0; flag2!='\n'; i++)
	{
		scanf("%d",&in2[i]);
		flag2=getchar();
	}
	n2=i;

	//将多项式1拆开
	for(i=0,j=0,k=0; i<n1; i++)
	{
		if(i%2==0)
		{
			num1[j]=in1[i];
			j++;
		}
		else
		{
			index1[k]=in1[i];
			k++;
		}
	}
	a1=k;

	//将多项式2拆开
	for(i=0,j=0,k=0; i<n2; i++)
	{
		if(i%2==0)
		{
			num2[j]=in2[i];
			j++;
		}
		else
		{
			index2[k]=in2[i];
			k++;
		}
	}
	a2=k;

    //相乘 
    k=-1; 
	for(i=0; i<a1; i++)
	{
		for(j=0; j<a2; j++)
		{
			
			flag=0;
			//若有 
			for(m=0; m<k+1; m++)
			{
				if((index1[i]+index2[j])==a[m][0])
				{
					a[m][1]+=num1[i]*num2[j];
					flag=1;
					break;
				}	
			}
			
			//若没有 
			if(flag==0)
			{   
			    k++;
				a[k][0]=index1[i]+index2[j];
				a[k][1]+=num1[i]*num2[j];	
			}
		}
	}

	for(i=0; i<k+1; i++)
	{
		for(j=0;j<k-i;j++)
		{
			if(a[j][0]<a[j+1][0])
			{
				temp1=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=temp1;
				
				temp2=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=temp2;
			} 
		} 
	}
	for(i=0;i<k+1;i++)
	{
		printf("%d %d ",a[i][1],a[i][0]);
	}
	return 0;
}



