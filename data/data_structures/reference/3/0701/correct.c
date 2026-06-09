#include <stdio.h>
#include <string.h>
char a[1000],b[1000];
int c[1000];
int main()
{
	gets(a);
	int i,k=0,d=0,j=0;
	int flag=0;
	for(i=0;i<=strlen(a)+1;i++)
	{
		if((a[i]>='1'&&a[i]<='9')||flag==1)
		{
			if(a[i]=='.')
			{
				if(a[0]!='0')
				c[0]=i-1; 
				continue;
			}
			if(a[0]=='0'&&flag==1)
			{
				c[j]=i-2;
				j++;
			}
			b[k]=a[i];
			k++;
			flag=1;		
		}
	}
	for(i=0;i<=strlen(b)-1;i++)
	{
		if(i==1)
		{
			printf(".");
		}
		printf("%c",b[i]);
	}
	printf("e");
	if(a[0]=='0'&&c[0]>0)
	c[0]=-c[0];
	printf("%d",c[0]); 
	return 0;
}

