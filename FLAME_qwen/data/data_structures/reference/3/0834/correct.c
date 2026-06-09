#include<stdio.h>
#include<string.h>
int main()
{
	char a[105];
	int i;
	scanf("%s",a);
	int z,n=0;
	if(a[0]=='0'&&a[1]=='.')
	{
		for(i=2;i<strlen(a);i++)
		{
			if(a[i]=='0')
			n++;
			else
			{
				n++;break;
			}
		}
		if(n==(strlen(a)-2))
		printf("%ce-%d",a[i],n);
		else{
			printf("%c.",a[i]);
			for(i+=1;i<strlen(a);i++)
			printf("%c",a[i]);
			printf("e-%d",n);
		}
	}
	else
	{
		z=0;
		for(i=0;a[i]!='.';i++)
		{
			z=10*z+a[i]-'0';
			n++;
		}
		n-=1;
		printf("%c.",a[0]);
		for(i=1;a[i]!='.';i++)
		printf("%c",a[i]);
		for(i=i+1;i<strlen(a);i++)
		printf("%c",a[i]);
		printf("e%d",n);
	 } 
    return 0;
}



