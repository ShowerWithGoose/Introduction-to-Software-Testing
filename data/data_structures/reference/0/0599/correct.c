#include <stdio.h>
#include <string.h>

int main()
{
	char a[100],b[200];
	gets(a);
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if((a[i]=='-')&&(a[i-1]>='a')&&(a[i+1]<='z')&&a[i-1]<a[i+1])
		{
			int j=a[i+1]-a[i-1];
			int k=1;
			while(j>k){
				printf("%c",a[i-1]+k);
				k++;
			}
			i++;
		}
		else if((a[i]=='-')&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1])
		{
			int j=a[i+1]-a[i-1];
						int k=1;
						while(j>k){
							printf("%c",a[i-1]+k);
							k++;
						}
						i++;
		}
		else if((a[i]=='-')&&a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1])
		{
			int j=a[i+1]-a[i-1];
						int k=1;
						while(j>k){
							printf("%c",a[i-1]+k);
							k++;
						}
						i++;
		}
		printf("%c",a[i]);
	} 
	return 0;
}
