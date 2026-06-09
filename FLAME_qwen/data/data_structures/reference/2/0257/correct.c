#include<stdio.h>
#include<string.h>
void fun(char *str)
{
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c;
}

int num(char *str,int s0)
{
	int i,num=0;
	for(i=s0;'0'<=str[i]&&str[i]<='9';i++)
	{
		num*=10;
		num+=(str[i]-'0');
	}
	return num;
} 

int main()
{
	char str[100];
	gets(str);
	fun(str);
	int sum=0,t=num(str,0);
	int i;
	for(i=1;str[i]!='=';i++)
	{
		switch (str[i])
			{
				case '*':
					t*=num(str,i+1);
					i++;
					break;
				case '/':
					t/=num(str,i+1);
					i++;
					break;
				case '+':
					sum+=t;
					t=num(str,i+1);
					i++;
					break;
				case '-':
					sum+=t;
					t=-num(str,i+1);
					i++;
				    break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					break;
			}
	}
	sum+=t;
	printf("%d",sum);
	return 0;
}


