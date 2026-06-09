#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char number[105];
int firstnum(char a[])
{
	int i, len = strlen(a);
	for (i = 0; i < len - 1; ++i) {
		if (a[i] > '0' && a[i] <='9')
		return i;
	}
	return i;
}
int getpoint(char a[])
{
	int i, len = strlen(a);
	for (i = 0; i <len ; ++i) {
		if (a[i] == '.')
		return i;
	}
	return i;
}
void clear(int num_, int po)
{
	int i, j = 0;
	for (i = num_; number[i] != '\0'; ++i) {
		if(i != po) {
			number[j++] = number[i];
		}
	}
	number[j] = '\0';
	return ;
}
int main()
{
	scanf("%s", number); 
	int i;
	for (i = 0; i < strlen(number); ++i) {
		if (number[i] == '-') {
			printf("-");
			break;
		}
	} 
	int num1 = firstnum(number), point = getpoint(number);
	int belowe = (num1 < point) ? (point - num1 - 1) : (point - num1);
	clear(num1,point);
	for (i = 0; i < strlen(number); ++i)
	{
		if(i == 1) printf(".");
		printf("%c", number[i]);
	}
	printf("e%d",belowe);
	return 0;
}



