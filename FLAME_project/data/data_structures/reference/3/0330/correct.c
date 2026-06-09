#include<stdio.h>
#include<string.h>
char a[1000];
int main()
{
	scanf("%s",a);
	int	len=strlen(a);
	char *p,*fir;
	int num;
	int sum;
	fir=a;
	p=strchr(a,'.');
	if(p-fir==1&&*(p-1)!='0')
	{
	for(int i=0;i<len;i++)
	printf("%c",a[i]);
	printf("e0");
	}
	else if(p-fir==1&&*(p-1)=='0')
	{
		for(num=1;*(p+num)=='0';num++){	
		}
		if(len-num==2)
		{
		printf("%c",a[len-1]);
		printf("e-%d",num);	
		}
		else
		{
			printf("%c.",*(p+num));
			for(int j=num+2;j<len;j++)
			{
				printf("%c",a[j]);
			}
			printf("e-%d",num);
		}
	}
	else
		{
			sum=p-fir-1;
			printf("%c.",a[0]);
			for(int k=0;k<sum;k++)
			{
				printf("%c",a[k+1]);
			}
			for(int j=0;j<len-sum-2;j++)
			{
				printf("%c",a[sum+2+j]);
			}
			printf("e%d",sum);
		}
	return 0;
	
}

