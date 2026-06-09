#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define eps 1e-15

char s[110];
char zg[110];
char xa[110];

int main(){
	gets(s);
	int judge = 0,num_zg = 0,num_xa = 0;
	int num_e = 0;
	
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i] == '.')
			judge = 1;
			
		else if(judge == 0)
			zg[num_zg++] = s[i];
		else
			xa[num_xa++] = s[i];
	}

	if(num_zg == 1 && zg[0] == '0')//整数部分为0 
	{
		for(int i = 0,j = 0;i<strlen(xa);i++)
		{
			if(xa[i] != '0')
			{
				num_e = j+1;
				break;
			}
			else
				j++;
		}
		
		if(num_xa - num_e == 0)//小数部分只有一个非0数 
			printf("%ce-%d",xa[num_e-1],num_e);
		else//小数部分有多个非零数 
		{
			printf("%c.",xa[num_e-1]);
			for(int i=num_e;i<num_xa;i++)
				printf("%c",xa[i]);
			printf("e-%d",num_e);
		}
	 } 

	else//整数部分有多位 
	{
		num_e = num_zg - 1;
		printf("%c.",zg[0]);
		for(int i = 1;i < num_zg;i++)
			printf("%c",zg[i]);
		for(int i = 0;i < num_xa;i++)
			printf("%c",xa[i]);
		printf("e%d",num_e);
	 } 
	return 0;
}


