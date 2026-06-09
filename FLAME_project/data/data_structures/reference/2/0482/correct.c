#include<stdio.h>
#include<string.h>

long long a = 0,b = 0,c = 0; 
char op1 = '+', op2;
int i = 0,j,k;
char s0[10000] = {0}, s[10000] = {0};

int main()
{
	gets(s0);
	int len = strlen(s0);
	for(j=0,k=0;j<len;j++)
	{
		if(s0[j] != ' ')
			s[k++] = s0[j];
	}
	s[k] = '\0';
	len = strlen(s);
	while(i < len - 1)
	{
		while(s[i] >= '0' && s[i] <= '9')
		{
			b = b * 10 + s[i] - '0';
			i += 1;	
			continue;
		}
		if(s[i] == '*'){
			i += 1;
			while(s[i] >= '0' && s[i] <= '9')
			{
				c = c * 10 + s[i] - '0';
				i += 1;	
			}	
			b = b * c;
			c = 0;
			continue;
		} 
		else if(s[i] == '/'){
			i += 1;
			while(s[i] >= '0' && s[i] <= '9')
			{
				c = c * 10 + s[i] -'0';
				i += 1;	
			}	
			b = b / c;
			c = 0;
			continue;
		} 
		if(s[i] == '+' || s[i] == '-'){
			if(op1 == '+'){
				a = a + b;
				b = 0;
				op1 = s[i];
				i += 1;
				continue;
			}
			else if(op1 == '-'){
				a = a - b;
				b = 0;
				op1 = s[i];
				i += 1;
				continue;
			}
		}
	}
	if(op1 == '+')
	{
		a = a + b;
	}
	else if(op1 == '-')
	{
		a = a - b;
	}
	printf("%lld",a);
} 

