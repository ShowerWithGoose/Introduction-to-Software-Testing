#include <stdio.h>
int main()
{
	char ori[105],formal[105];
	int i,j,k;
	gets(ori);
	if(ori[0]=='0')
	{
	for(i=2;i<strlen(ori);i++)
		{
		if(ori[i]!='0')
		{
		printf("%c",ori[i]);
		break;
		}
		}
	for(j=i+1;j<strlen(ori);j++)
		{	if(j==i+1) printf(".");
			printf("%c",ori[j]);
		}
	printf("e-%d",i-1);
	}
	else
	{
		for(i=0;i<strlen(ori);i++)
		{
			if(ori[i]=='.')
			break;
		}
		printf("%c.",ori[0]);
		for(j=1;j<i;j++)
		printf("%c",ori[j]);
		for(k=i+1;k<strlen(ori);k++)
		printf("%c",ori[k]);
		printf("e%d",i-1);
	}
	return 0;
}

