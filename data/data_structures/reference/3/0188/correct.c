#include<stdio.h>
#include<string.h>
char num[1000]; 
int xiao();
int da();
int main()
{
	scanf("%s",num);
	if(num[1]=='.'&&num[0]=='0') xiao();
	else if(num[1]=='.'&&num[0]!='0') printf("%se0",num);
	else da();
	return 0;
}
int xiao()
{
	int i=2;//num[2] 0.?
	while(num[i]=='0') i++; //zhao dao !0 
	printf("%c",num[i]); // di yi wei
	int j=i+1;
	if(j<strlen(num)) printf(".");
	while(j<strlen(num))
	{
		printf("%c",num[j]);
		j++;
	}
	printf("e-%d",i-1);
}
int da()
{
	printf("%c.",num[0]); //?.
	int i=0,j=1;
	while(j<strlen(num)) //shu zi
	{
		if(num[j]!='.') printf("%c",num[j]);
		else i=j;
		j++;
	}
	printf("e%d",i-1);
}

