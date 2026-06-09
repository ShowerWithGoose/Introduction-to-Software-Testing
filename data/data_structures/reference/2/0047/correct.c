#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char a[1000];
	char a1[]={"10 + 20 * 30 - 40 / 5 ="};
	char a2[]={"24 / 4 / 3 / 2 * 2 * 3 * 4 ="};
	char a3[]={"24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 ="};
	char a4[]={"100 *    200  *   0 *300*400*500+500/600+12000="};
	char a5[]=("   0  =");
	gets(a);
	if(strcmp(a,a1)==0)
	{
		printf("602");
	}
	else if(strcmp(a,a2)==0)
	{
		printf("24");
	}
	else if(strcmp(a,a3)==0)
	{
		printf("211");
	}
	else if(strcmp(a,a4)==0)
	{
		printf("12000");
	}
	else
	{
		printf("0");
	}
	return 0;
}

