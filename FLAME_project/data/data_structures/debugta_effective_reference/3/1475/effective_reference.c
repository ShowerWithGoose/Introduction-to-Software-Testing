#include<stdio.h>
#include<string.h>
#include<ctype.h> 

void del_char(char* str, char ch);
int main() {
	
	char s[101];
	gets(s);
	int len = strlen(s);
	int point_location1 = 0, point_location2 = 0;
	int point_move = 0;
	int flag1 = 0;//判断首位数字后是否存在小数点
	int flag2 = 0;//判断首位数字后是否全为0
	int flag3 = 0;//判断小数点后是否都为0
	int i,j,k; 
	if (s[0] != '0') {//首位不是0
		printf("%c",s[0]);
		for (i = 1; i < len + 1; i++) {
			if (s[i] == '.') {
				point_location1 = i;
				flag1 = 1;
				for (j = len-1; s[j] == '0';j--) {//123.100
					 s[j]=' ';
				}
				del_char(s,' ');
			}
			if (s[i] != '0' && s[i] != '.') flag2 = 1;
			if (s[i] == 0) flag2 = 2;
			
		}
		//以下是判断与输出
		if (flag2 == 2&&flag1==0) {//类似情况10000，首位后面全是0
			printf("e%d", len - 1);
		}
		if (flag1 == 0 && flag2 == 1) {//类似情况1234
			printf(".");
			for (j = 1; s[j] != '\0'; j++) {
				printf("%c", s[j]);
			}
			printf("e%d", len - 1);
		}
		if (flag1==1) {//11.234
			printf(".");
			del_char(s, '.');
			len = strlen(s);
			for (j = 1; s[j] != '\0'; j++) {
				printf("%c", s[j]);
			}
			printf("e%d", point_location1 - 1);
		}
		

	}
	if (s[0] == '0') {//首位为0
		
		for (i = 0; i < len ; i++) {
			if (s[i] == '.') {//0.0000223400
				point_location1 = i;
			}
			if (s[i] <= '9' && s[i] >= '1') {
				point_location2 = i;break;
			}
		}
		del_char(s, '.');
		for (j = 0; s[j]=='0'; j++) {
			s[j] = ' ';
		}
		for (j = len - 2; s[j] == '0'; j--) {
			s[j] = ' ';
		}
		del_char(s, ' ');
		printf("%c", s[0]);
		if (strlen(s) >= 2) {
			printf(".");
			for (k = 1; s[k] != '\0'; k++) {
				printf("%c", s[k]);
			}
			printf("e-%d", point_location2 - point_location1);
		}
		if (strlen(s) == 1) {
			printf("e-%d", point_location2 - point_location1);
		}
	}
	





	return 0;
}
void del_char(char* str, char ch) {

	char* p = str;
	char* q = str;
	while (*q) {

		if (*q != ch) {
			*p++ = *q;
		}
		q++;

	}
	*p = '\0';

}



