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
		int k = begin;
		printloop(begin + 1, n, string);
		for ( k = begin+1; k <= n; k++)
		{
			swap(string, begin, k);
			if (k >= begin + 2)
			{
				int record=string[k];
				int o;
				for (o = k ; o >= begin + 2; o--)
				{
					string[o] = string[o - 1];
				}
				string[o] = record;
			}
			printloop(begin + 1, n, string);
			if (k >= begin + 2)
			{
				int record = string[begin+1];
				int o;
				for (o = begin + 1; o <= k-1; o++)
				{
					string[o] = string[o + 1];
				}
				string[k] = record;
			}
			swap(string, begin, k);

		}
	}



}



