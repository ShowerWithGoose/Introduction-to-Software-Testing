#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000];
	int m,n,k;
	int i,j,s;
	
	gets(a);
	m=strlen(a);        //  m是总长度 
	
	for(i=0;i<m;i++)
	{
		if(a[i]=='.') break;
	}
	
	n=i;                //  n是小数点的位置 
	
	if(a[0]=='0' && n==1)
	{
		for(i=2;i<m;i++)
		{
			if(a[i]>'0') break;
		}
		k=i;            //  k是第一个不为0的数
		
		s=k-n;
		
		if(k!=m-1)
		{
			printf("%c.",a[k]);
			for(i=k+1;i<m;i++)
			{
				printf("%c",a[i]);
			}
		}
		else
		{
			printf("%c",a[k]);
		}
		printf("e-%d",s);
	}
	if(a[0]!='0')
	{
		s=n-1;
		
		printf("%c.",a[0]);
		for(i=1;i<m;i++)
		{
			if(i!=n) printf("%c",a[i]);
		}
		
		printf("e%d",s);
	}
	
	return 0;
}


