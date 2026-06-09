#include <stdio.h>
#include<string.h>
int main(void)
{
	int i,a[100],len,j,zz = 0;
	char op[100];
	for(i = 0;i<100;i++)
	{
		
		scanf("%d %c",&a[i],&op[i]);
		if(op[i] == '=')
		{
			len = i;
			break;
		}
		
	}
	for(i = 0;i<len;i++)
	{
		if(op[i] == '*')
		{
			a[i+1] = a[i] * a[i + 1];
			a[i] = 0;
		}
		if(op[i] == '/')
		{
			a[i+1] = a[i] / a[i + 1];
			a[i] = 0;
		}
	}
	for(i = 0;i < len;i++)
	{
		if(op[i] == '-')
		{
			for(j = 1;op[i] == '-';j++)
			{
				a[i+j] = -1*a[i+j];
				if(a[i+j]!=0)
					break;
			}
		}
	}
	
	for(i = 0;i<=len;i++)
	{
		zz = a[i] + zz;
		
	}
	printf("%d",zz);
	return 0;
}

