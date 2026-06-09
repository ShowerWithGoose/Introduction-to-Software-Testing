#include <stdio.h>
#include <string.h>
char a[100005],b[100005];
int main()
{
	int i=0,j=0,flag=0;
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-')
		{
			if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))flag=1;
		}
		if(flag==1)
		{
				
				int p=1;
				if(a[i-1]<=a[i+1])
				{
					while(a[i-1]+p!=a[i+1])
					{
						b[j++]=a[i-1]+p;
						p++;
					}
				}
				if(a[i-1]>=a[i+1])
				{
					while(a[i-1]-p!=a[i+1])
					{
						b[j++]=a[i-1]-p;
						p++;
					}
				}
			i++;
		}
		b[j++]=a[i];
		flag=0;			
	}
	b[j]='\0';
	puts(b);
}




