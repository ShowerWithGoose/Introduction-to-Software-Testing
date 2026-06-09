#include<stdio.h>
#include<string.h>
void fre(char *arr)
{
	for(int i=strlen(arr)-1;i>=0;i--)
		arr[i]='\0';
	return 0;
}

int main()
{
	char arr[100];
	fre(arr);
	gets(arr);
	for(int i=0;i<strlen(arr);i++)
	{
		printf("%c",arr[i]);
		if(arr[i+1]=='-')
		{
			if((islower(arr[i])&&islower(arr[i+2]))&&(arr[i]-arr[i+2])<0)
			{
				int nub=arr[i+2]-arr[i];
				for(int j=1;j<nub;j++)
					printf("%c",arr[i]+j);
				i++;
			}
			else if((isupper(arr[i])&&isupper(arr[i+2]))&&(arr[i]-arr[i+2])<0)
			{
				int nub=arr[i+2]-arr[i];
				for(int j=1;j<nub;j++)
					printf("%c",arr[i]+j);
				i++;
			}
			else if((isdigit(arr[i])&&isdigit(arr[i+2]))&&(arr[i]-arr[i+2])<0)
			{
				int nub=arr[i+2]-arr[i];
				for(int j=1;j<nub;j++)
					putchar(arr[i]+j);
				i++;
			}
		}
	}
	return 0;
} 

