#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
char s0[105];
char s1[105];
int num[105];
char op[105] = {'+'};

void del(char* str, int l) 
{
	int j = 0;
	for (int i = 0; i < l ; i++) 
	{
		if (str[i] != ' ') 
		{
			s1[j++] = str[i];
		}
	}
}

int main() {
//读入字符串以及删除空格
	gets(s0);
	int l = strlen(s0);
	del(s0, l);
//转化为计算式
	int j = 1, k = 1;
	for (int i = 0; s1[i] != '='; i++) 
	{
		if (s1[i] >= '0' && s1[i] <= '9') 
		{
			num[k] = num[k] * 10 + s1[i] - '0';
			if (!(s1[i + 1] >= '0' && s1[i + 1] <= '9')) 
			{
				
					if (op[j - 1] == '*' || op[j - 1] == '/') 
					{
						if (op[j - 1] == '*') num[k - 1] *= num[k];
						else num[k - 1] /= num[k];
						num[k] = 0;
						j--;
						op[j] = '\0';
					
						if (s1[i + 1] == '+' || s1[i + 1] == '-' || s1[i + 1] == '=') 
						{
							if (op[j - 1] == '+' || op[j - 1] == '-') 
							{
								k--;
								if (op[j - 1] == '+') num[k - 1] += num[k];
								else num[k - 1] -= num[k];
								num[k] = 0;
								j--;
								op[j] = '\0';
							}
						}
					} 
					else 
					{
						if (s1[i + 1] == '+' || s1[i + 1] == '-'|| s1[i + 1] == '=') 
						{
							if (op[j - 1] == '+' || op[j - 1] == '-') 
							{
								if (op[j - 1] == '+') num[k - 1] += num[k];
								else num[k - 1] -= num[k];
								num[k] = 0;
								j--;
								op[j] = '\0';
							}
						} 
						else 
						{
							k++;
						}
					}
			}

		} 
		else 
		{
			op[j++] = s1[i];
		}
	}
	printf("%d", num[0]);
	return 0;
}

