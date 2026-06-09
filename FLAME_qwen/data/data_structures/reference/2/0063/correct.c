#include<stdio.h>
int a[100]={0};

char b[100]={'+'};
int main()
{
	int i,j,flag=0;
	for(i=0;i<9999;i++)
	{
		scanf("%d %c",&a[1],&b[1]);
//		if(b[1]=='*'||b[1]=='/')
//			flag=1;
		while(b[1]=='*'||b[1]=='/')
		{
			scanf("%d %c",&a[2],&b[2]);
			if(b[1]=='*')
				a[1]=a[1]*a[2];
			else
				a[1]=a[1]/a[2];
			b[1]=b[2];
		}
		if(b[0]=='+')a[0]=a[1]+a[0];
		else if(b[0]=='-')a[0]=a[0]-a[1];
		b[0]=b[1];
		if(b[0]=='=')
		{
			printf("%d",a[0]);
			break;
		}
	}
	return 0;
}

/*int qui[1000];                    //整数数组 
void ch(char c[],int in[])        //去掉空格,
{
	int i,j=1,seq[1000],n=0,sum=0;
	for(i=0;i<500;i++)
	{
		if(c[i]==' ')
		{
			for(j=i;j<500;j++)
				c[j]=c[j+1];
		}
	}
	for(i=0;i<500;i++)                      //在数组里找数字 
	{
		if(c[i]>=48 &&c[i]<=57)             //发现数字 
		{
			seq[i]=c[i]-48;
			for(j=1;j<500;j++)              
			{
				if(c[i+j]>=48 && c[i+j]<=57)//看下一位还是不是
					n++;                    //记录数字总数 
				else
					break;
			}
			for(j=0;j<n;j++)
			{
				sum+=pow(10,j)*seq[i+n-j];
			}
			in[i]=sum;		
		}
	}
}

void cal(char a[])
{
	int i;
	for(i=0;i<500;i++)
	{
		if(a[i]=='*'||a[i]=='/')
		{
			
		}
	}
}

int main()
{
	int i;
	char quc[1000];
	gets(quc);
	ch(quc,qui);
//	puts(quc);
	for(i=0;i<15;i++)
	{
		if(qui[i]!=0)
			printf("%d",qui[i]);
	}
	return 0;
} */

