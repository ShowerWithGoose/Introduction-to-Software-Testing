#include <stdio.h>
#include <string.h>
char a[100],b[150];
int main()
{
	int i,n,j=0;
	char m;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		b[j]=a[i];j++;
		if(a[i+1]=='-')
		{
			if((a[i]>='0'&&a[i]<='9'&&a[i+2]>='0'&&a[i+2]<='9')||(a[i]<='z'&&a[i]>='a'&&a[i+2]<='z'&&a[i+2]>='a')||(a[i]<='Z'&&a[i]>='A'&&a[i+2]<='Z'&&a[i+2]>='A'))
		{
			m=a[i];	
			i++;
			while(1){
				m++;
				if(m==a[i+1])
				break;
				else
				b[j]=m;
				j++;
			}
		}
		}
	
	}
	printf("%s",b);
	return 0;
}



