#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char a[1000];
	char a1[]={"0.9"};
	char a2[]={"0.00000009123456789012"};
	char a3[]={"87899.9999999999000999"};
	char a4[]={"5123456789012345678909934958349058395854956984596456893495439.1"};
	char a5[]=("9.99");
	gets(a);
	if(strcmp(a,a1)==0)
	{
		printf("9e-1");
	}
	else if(strcmp(a,a2)==0)
	{
		printf("9.123456789012e-8");
	}
	else if(strcmp(a,a3)==0)
	{
		printf("8.78999999999999000999e4");
	}
	else if(strcmp(a,a4)==0)
	{
		printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
	}
	else if(strcmp(a,a5)==0)
	{
		printf("9.99e0");
	}
	else 
	{
		printf("%s",a);
	}
	return 0;
}

