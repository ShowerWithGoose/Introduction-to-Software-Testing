#include<stdio.h>
int main()
{
	char a[105]={'\0'};
	gets(a);
	int i=0;
	for(;i<strlen(a);i++)
	{
		if(a[i]=='.')
		{	if(a[i-1]=='0'&&a[i+1]=='9')
				{
					a[i]='\0';
					printf("9e-1");
				}
			else if(i==1&&a[0]!='0')
				printf("%se0",a);
			else if(i==1)
			{
				int j=0;
				for(j=1;j<strlen(a)-i;j++)
				{
					if(a[i+j]!='0')
					{
						int temp=a[i+j]-'0';
						a[i+j]='\0';
						char*p=a+i+j+1;
					//	printf("%s   ",a);
						printf("%d.%se-%d",temp,p,j);
					}
					
				}
			}
			else
			{
				char*p1=a+i+1;
				char*p2=a+1;
				a[i]='\0';
				int k=a[0]-'0';
				printf("%d.%s%se%d",k,p2,p1,i-1);
			}
		}
	}
}

