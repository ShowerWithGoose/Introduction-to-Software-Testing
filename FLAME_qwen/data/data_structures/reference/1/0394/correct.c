#include<stdio.h>
#include<string.h>
#include<math.h> 
int jiecheng( int a)
{
	if(a>1)
	return a*jiecheng(a-1);
	else
	return 1;
}
int main()
{
	int b;
	int a[10];
	scanf("%d",&b);//输入数字 比如输入3 则应输出123 132 213 231 312 321 
	int i,j,k;
	int flag;
	int min=0 ,max=0,ji=1,he=0;
	for(i=0;i<b;i++)
	min+=(i+1)*pow(10,b-1-i); 
	for(i=b;i>=0;i--)
	max+=i*pow(10,i-1);
	for(i=min;i<=max;i++)  //min =123  max=321 然后开始从这两个数之间遍历 从小到大找打符合条件的输出 
	{he=0,ji=1;	int m;m=i;
		a[0]=m%10;
		for(j=1;j<b;j++)
		{	m/=10;
			a[j]=m%10;
		}
		for(j=0;j<b;j++)
		{
			ji*=a[j];
			he+=a[j];
		}
		if(ji==jiecheng(b)&&he==(1+b)*b/2)
		{
			for(k=b-1;k>0;k--)
			printf("%d ",a[k]);
			printf("%d\n",a[k]);
		}
		
	}
	
	return 0;
}

