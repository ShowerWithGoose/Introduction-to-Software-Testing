#include <stdio.h>
#include <string.h>
char sign[100], com[100][100];
int stack[100];
int cacul(char ch) {
	if (ch == '+') return 1;
	if (ch == '-') return 2;
	if (ch == '*') return 3;
	if (ch == '/') return 4;
}
void RNP(char str[]) {
	int i = 0, j = 0, k = 0;
	for (i, j, k;i < strlen(str) ;) {
		if ('0' <= str[i] && str[i] <= '9') {
			int sum = 0;
			for (i;'0' <= str[i] && str[i] <= '9';i++) {
				sum = sum * 10 + (str[i] - '0');
			}
			stack[j++] = sum;
		}
		else if (str[i] == ' ') {i++;continue;}
		else{
			if (k == 0 || com[str[i]][sign[k - 1]] == '>') sign[k++] = str[i++];
			else if (0 < k && com[str[i]][sign[k - 1]] == '<') {
				for (int u = 0; ;u++) {
				if (com[str[i]][sign[k - 1]] == '<') {
					int re;
					if (cacul(sign[k - 1]) == 1) re = stack[j - 2] + stack[j - 1];
					if (cacul(sign[k - 1]) == 2) re = stack[j - 2] - stack[j - 1];
					if (cacul(sign[k - 1]) == 3) re = stack[j - 2] * stack[j - 1];
					if (cacul(sign[k - 1]) == 4) re = stack[j - 2] / stack[j - 1];
					j -= 2;
					stack[j++] = re;
					k--;
				}else break;
				}
				sign[k++] = str[i++];
			}
			else if (0 < k && str[i] == '=') {
				for (; 0 < k;) {
				
				int re;
				if (cacul(sign[k - 1]) == 1) re = stack[j - 2] + stack[j - 1];
				if (cacul(sign[k - 1]) == 2) re = stack[j - 2] - stack[j - 1];
				if (cacul(sign[k - 1]) == 3) re = stack[j - 2] * stack[j - 1];
				if (cacul(sign[k - 1]) == 4) re = stack[j - 2] / stack[j - 1];
				j -= 2;
				stack[j++] = re;
				k--;
			}
				break;
			}
		}
//		for (int u = 0; u < j; u++) printf("%d ", stack[u]);
//		printf("\n");
	}
	
	printf("%d\n", stack[0]);
	return;
}
int main() {
	com['+']['+'] = com['+']['-'] = com['-']['+'] = com['-']['-'] = com['+']['*'] = com['+']['/'] = com['-']['*'] = com['-']['/'] = com['*']['*'] = com['*']['/']= com['/']['/']= com['/']['*'] = '<';
	com['*']['-'] = com['*']['+'] = com['/']['+'] = com['/']['-'] = '>';
	com['=']['*'] = com['=']['/'] = com['=']['+'] = com['=']['-'] = ' '; 
	char str[100];
	gets(str);
	RNP(str);
	return 0;
}


