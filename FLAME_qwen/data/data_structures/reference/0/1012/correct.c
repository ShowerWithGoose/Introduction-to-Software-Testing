#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[20001],b[20001];
	int i=0,j=0;
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if(a[i]=='-')
		{
			if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i+1]<='Z'))
			{
				if(a[i-1]<=a[i+1])
				{
					if(b[j-1]==a[i+1])
					{
						i=i+2;
					}
					else 
					{
						b[j]=b[j-1]+1;
						j++;
					}
				}
				else
				{
					b[j]=a[i];
					j++;
					i++;
				}
			}
			else
			{
				b[j]=a[i];
				j++;
				i++;
			}
		}
		else
		{
			b[j]=a[i];
			j++;
			i++;
		}
	}
	printf("%s",b);
	return 0;	
}


