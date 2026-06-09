#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[200];
	int i,j;
	gets(a);
	for(i,j=0;i<strlen(a);i++)
	{
		if(a[i]=='-'&&i-1>=0&&i+1<strlen(a))
		{
			if(a[i-1]<a[i+1]&&((a[i-1]>='0'&&a[i+1]<='9')||(a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')))
			{
				for(int k=1;k<a[i+1]-a[i-1];k++)
				{
					b[j]=a[i-1]+k;
					j++;
				}
			}
			else
			{
				b[j]=a[i];
				j++;
			}
		}
		else
		{
			b[j]=a[i];
			j++;
		}
	}
	for(int x=0;x<j;x++)
	{
		printf("%c",b[x]);
	}
	return 0;
}



