#include <stdio.h>
#include <string.h>
char a[50],b[50];
int main()
{
	int x,n,i=0,j,m=0;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;i++)
		{
			if(a[i]=='.')
			m=i;
		}
	if(a[0]=='0')
	{
		if(a[1]=='\0')
		printf("0");
		else{
			i=2;
		while(a[i]=='0')
		{
			i++;
		}
		x=i-m;
		b[0]=a[i];
		if(i!=n-1){
			b[1]='.';
			for(i=i+1,j=2;i<n;i++,j++)
			{
				b[j]=a[i];
			}
		}
		printf("%se-%d",b,x);
		}
	}
	else{
		if(m==0)
		{
			x=n-1;
		}
		else
		x=m-1;
		if(m!=0||n!=1)
		{
		b[0]=a[0];
		b[1]='.';
		for(i=1,j=2;i<n;i++,j++)
		{
			if(a[i]=='.')
			{
				i++;
			}
			b[j]=a[i];
		 } 
		 printf("%se%d",b,x);
		}
		else
		printf("%se0",a);
	}
	return 0;
}

