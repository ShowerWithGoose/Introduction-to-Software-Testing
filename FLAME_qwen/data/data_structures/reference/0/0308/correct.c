#include<stdio.h>
#include<string.h>
int main()
{
	char a[2000000];
	gets(a);
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(i==0||i==strlen(a)-1||a[i]!='-')
			printf("%c",a[i]);
		if(i>0&&a[i]=='-')
		{
			int flag=0;
			if((a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>='0')||(a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>='a')||(a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>='A'))
			{
				if(a[i-1]<a[i+1]) {
					flag=1;
					int j;
					for(j=1;j<a[i+1]-a[i-1];j++) 
						printf("%c",j+a[i-1]);
				}
			}
			if(flag==0)
				printf("%c",a[i]);
		}

	}
	return 0;
}

