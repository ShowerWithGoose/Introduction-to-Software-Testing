#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printloop(int begin, int n, char* string);

void swap(char* string, int begin, int k);
int main() {
	int n;
	scanf("%d", &n);
	char string[100];
	for (int i = 1; i <= n; i++)
	{
		string[i] = i;
	}
	printloop(1,n,string);

	

	
}
	
void swap(char* string, int begin, int k)
{
	int inter = string[begin];
	string[begin] = string[k];
	string[k] = inter;
	
}
	
void printloop(int begin, int n, char* string)
{
	if (begin == n)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", string[i]);
		}
		printf("\n");
	}
	else
	{
		for (int k = begin; k <= n; k++)
		{
			swap(string, begin, k);
			printloop(begin + 1, n, string);
			swap(string, begin, k);

		}
	}



}


	

	

