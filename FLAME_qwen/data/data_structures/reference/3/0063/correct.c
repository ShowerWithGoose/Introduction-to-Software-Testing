#include<stdio.h>
char qu[1000];
int m;                    //m为计.前0数字个数 
int n;                    //n为计.后0的个数 
int swp(char a[])         //找.函数 
{
	int i;
	for(i=0;i<100;i++)
	{
		if(a[i]=='.')
		{
			return i;
		}
	}
}

void re1(char a[])             //重塑0.情况下的qu数组 
{
	int i,j,k=1;
	for(i=2;i<100;i++)
	{
		if(a[i]!='0')
		{
			n=i-1;
			a[0]=a[i];
//			a[1]='.';
			for(j=2;j<100;j++)
			{
				a[j]=a[i+k];
				k++;
			}
			k=1;
			break;
		}
	}
	if(a[2]=='\0')
		a[1]='\0';
}

void re2(char a[])             //重塑n.情况下的qu数组 
{
	int i,j,mre,hold;
	for(i=0;i<100;i++)
	{
		if(a[i]=='.')
		{
			m=i-1;
			mre=m;
			for(j=m;j>0;j--)
			{
				hold=a[mre];
				a[mre]=a[mre+1];
				a[mre+1]=hold;
				mre--;
			}
			break;
		}
	}
	if(a[2]=='\0')
		a[1]='\0';
}

int main()
{
	int where,i;
//	char qu[1000];
	gets(qu);
	where=swp(qu);
//	printf("%d",where);
	if(where==1)
	{
		if(qu[0]=='0')
		{
			re1(qu);
			printf("%s",qu);
			printf("e-%d",n);
			return 0;
		}
		else
		{
			printf("%s",qu);
			printf("e0");
			return 0;
		}
	}
	else
	{
		re2(qu);
		printf("%s",qu);
		printf("e%d",m);
	}
	return 0;
}

