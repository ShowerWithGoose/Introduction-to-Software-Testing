#include<stdio.h>
#include<string.h>
#include<math.h>
char s[99999];
int wei, first=-1,length; //first记录起始在哪一位，wei记录位数
int main() {
	gets(s);
	length = strlen(s);
	for (int i = 0; i < length ; i++) {
		if (s[i] == '0') {
			continue;
		} 
		else if (s[i] != '0' && s[i] != '.') {
			if (first != -1)
				continue;
			if (s[0] != '0')
				first = i ; //大于一
			else if (s[0] == '0') //分情况
				first = i ; //小于一
		} 
		else if (s[i] == '.') {
			wei = i - 1; //记录小数点前是几位数，小于一时为零
		}
	}
	if (s[0] == '0') {
		if(first + 1 >= length )
		{
			printf("%c", s[first]);
		}
		else 
		printf("%c.", s[first]);
		for (int i = first + 1; i < length ; i++) {
			printf("%c", s[i]);
		}
		printf("e-%d", first - wei-1);
	} 
	else {
		printf("%c.", s[first]);
		for (int i = first + 1; i < length; i++) {
			if (s[i] == '.')
				continue;
			printf("%c", s[i]);
		}
		printf("e%d", abs(first - wei));
	}
}

