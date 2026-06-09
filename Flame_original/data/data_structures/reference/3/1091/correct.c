#include<stdio.h>
#include<string.h>
char num[100];
int main()
{
	int i,j,k=1,h,p;
	scanf("%s",num);
	if(num[0]=='0'&&num[1]=='.')
	{
			for(i=2;i<strlen(num);i++)
			{
				if(num[i]!='0')
				break;
			}
			printf("%c",num[i]);
			if(i<strlen(num)-1)
			{
				printf(".");
			}
		for(j=i+1;j<strlen(num);j++){
			printf("%c",num[j]);
		}
		printf("e-%d",i-1);
	}
	else if(num[1]!='.')
	{
		printf("%c.",num[0]);
		do
		{
			printf("%c",num[k]);
			k++;
		}while(num[k]!='.');
		for(h=k+1;h<strlen(num);h++)
		{
			printf("%c",num[h]);
		}
		printf("e%d",k-1);
	}
	else{
	for(p=0;p<strlen(num);p++)
	{
		printf("%c",num[p]);
	}
	printf("e0");
	}
	return 0;
}

