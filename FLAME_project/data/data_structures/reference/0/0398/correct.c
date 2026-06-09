#include <stdio.h>
#include <string.h>
char a[1000],b[2000];
int fc(int x)
{
	if(a[x+1]>a[x-1]){
	
	if(a[x-1]<='z'&&a[x-1]>='a')
	{
		if(a[x+1]<='z'&&a[x+1]>='a')
			return 1;
	}
	else if(a[x-1]<='Z'&&a[x-1]>='A')
	{
		if(a[x+1]<='Z'&&a[x+1]>='A')
			return 2;
	}
	else if(a[x-1]<='9'&&a[x-1]>='0')
	{
		if(a[x+1]<='9'&&a[x+1]>='0')
			return 3;
	}}
	return 0;
}
int main()
{
	
	scanf("%s",a);
	int i,j,k;
	
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i+1]=='-'&&(fc(i+1)))
		{
				for(k=0;k<(a[i+2]-a[i]);j++,k++)
				{
					b[j]=a[i]+k;
				}
				i++;	
		}
		else 
		{
			b[j++]=a[i];
		}
		
	}
	b[j]='\0';
	printf("%s",b);
	return 0;
}



