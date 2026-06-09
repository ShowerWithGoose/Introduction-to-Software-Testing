#include<stdio.h> 
#include<string.h> 
int main() {
	char g[1000];
	int m[1000]={0}, len[1000] = {0},j=0;//m记录每个-出现的位置，len记录每次需扩展的位数，j为-的总个数
	gets(g);
	for (int i = 0; i < strlen(g); i++) {
		if ('-' == g[i]) {
			m[j] = i;
			len[j] = g[i + 1] - g[i - 1] - 1;
			j++;
		}
	}//遍历得到‘-’的信息
	
	for (int i = 0; i < m[0]-1; i++) {
		printf("%c", g[i]);
	}//输出最开始的一段

	
	
	
	for (int i = 0; i < j; i++) {
		if ((((g[m[i] - 1] >= 'a' && g[m[i] - 1] <= 'z') && (g[m[i] + 1] >= 'a' && g[m[i] + 1] <= 'z')) || ((g[m[i] - 1] >= 'A' && g[m[i] - 1] <= 'Z') && (g[m[i] + 1] >= 'A' && g[m[i] + 1] <= 'Z'))|| ((g[m[i] - 1] >= '0' && g[m[i] - 1] <= '9') && (g[m[i] + 1] >= '0' && g[m[i] + 1] <= '9'))) && (g[m[i] - 1] < g[m[i] + 1])) {
			for (int d = 0; d < len[i] + 1; d++) {
				printf("%c", g[m[i] - 1] + d);//从-前一个字符开始向后输出到-之后的一个字符(不包括）
			}
		}
		else {
			printf("%c-", g[m[i] - 1]);
		}
			if (g[m[i] + 2] == '-') {
				continue;
			}
			if (g[m[i] + 2] == '\0') {
				continue;
			}
			else {
				for (int k = 0; k <= m[i + 1] - m[i] - 3; k++) {
					printf("%c", g[m[i] + 1 + k]);
				}
			}
		
		
	}//周期输出中间段
	
	for (int i = 0; g[m[j - 1] + 1 + i] != '\0'; i++) {
		printf("%c", g[m[j - 1] + 1 + i]);
	}//输出最后的一段
	
	return 0;
}
