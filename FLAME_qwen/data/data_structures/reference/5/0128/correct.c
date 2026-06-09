#include<stdio.h>
#include<string.h>
void bubbleSort(int [],int [],int); 
int main()
{
	char a[100],b[100];
	int a1[100]={0},a2[100]={0},b1[100]={0},b2[100]={0},c1[100],c2[100];//1代表系数2代表指数 
	int n=0,m=0,i,j,q=0,flag1=0,flag2=0,k;//n,m=top
	gets(a);
	gets(b);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' ')
		{
			if(flag1%2==0)
			{
				j=a[i]-48;
				a1[n]=a1[n]*10+j;
			}
			else if(flag1%2==1)
			{
				j=a[i]-48;
				a2[n]=a2[n]*10+j;
			}
		}
		else
		{
			flag1++;
			if(flag1%2==0)
			{
				n++;
			}
		}
	}
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]!=' ')
		{
			if(flag2%2==0)
			{
				j=b[i]-48;
				b1[m]=b1[m]*10+j;
			}
			else if(flag2%2==1)
			{
				j=b[i]-48;
				b2[m]=b2[m]*10+j;
			}
		}
		else
		{
			flag2++;
			if(flag2%2==0)
			{
				m++;
			}
		}
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			c1[q]=a1[i]*b1[j];
			c2[q]=a2[i]+b2[j];
			q++;
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=i+1;j<q;j++)
		{
			if(c2[i]==c2[j])
			{
				c1[i]=c1[i]+c1[j];
				for(k=j+1;k<q;k++)
				{
					c1[k-1]=c1[k];
					c2[k-1]=c2[k];
				}
				q--;
			}
		}
	}
	bubbleSort(c1,c2,q);
	for(i=0;i<q;i++)
	{
		printf("%d %d ",c1[i],c2[i]);
	}
	return 0;
}
void bubbleSort(int x[],int y[],int n)
{
	int i,j,hold,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-1;j++)
		{
			if(y[j]<y[j+1])
			{
				hold=y[j];
				y[j]=y[j+1];
				y[j+1]=hold;
				hold=x[j];
				x[j]=x[j+1];
				x[j+1]=hold;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}



