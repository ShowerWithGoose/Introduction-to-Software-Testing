#include<stdio.h>
#include<string.h>
int cal(char c,int a ,int b)
{
	switch(c){
		case '+':return a + b;
		case '-':return a - b;
		case '*':return a * b;
		case '/':return a / b;
	}
}
int main()
{
	char s[120];
	int cha[120]={0},num1[80]={0},num2[80]={0};
	int i,j,k1=1,k2=1,k,l,chan=0;
	gets(s);
	for(i = 0,j = 0;s[i] != '=';i++)
	{
		if(s[i] != ' ')
			s[j++] = s[i];
	}
	s[j] = '\0';k = strlen(s);
	for(i = 0; i < k; i++)
	{
		if(s[i] == '*' || s[i] == '/'|| s[i] == '+' || s[i] == '-')
			num1[k1++] = i;
		if(s[i] == '+' || s[i] == '-')
			num2[k2++] = i;
		else
		{
			for(l = i; s[l] >= '0'&& s[l] <='9';l++)
				chan = chan * 10 + s[l] - '0';
			cha[l-1] = chan;
			chan = 0;
			if(s[l] == '*' || s[l] == '/'|| s[l] == '+' || s[l] == '-')
				num1[k1++] = l;
			if(s[l] == '+' || s[l] == '-')
				num2[k2++] = l;
			i = l;
		}
	}
	num2[k2++] = k;num1[k1++] = k;
	for(i = 1; i <= k1; i++)
	{
		if(s[num1[i]] == '*' || s[num1[i]] == '/')
			cha[num1[i+1]-1] = cal(s[num1[i]],cha[num1[i]-1],cha[num1[i+1]-1]);
		
	}
	for(i = 1; i <= k2; i++)
	{
		if(s[num2[i]] == '+' || s[num2[i]] == '-')
		{
			cha[num2[i+1]-1] = cal(s[num2[i]],cha[num2[i]-1],cha[num2[i+1]-1]);	
		}	
	}
	printf("%d",cha[k-1]);
return 0;
}

