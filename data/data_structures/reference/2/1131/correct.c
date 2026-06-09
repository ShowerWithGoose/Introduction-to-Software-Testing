#include <stdio.h>
#include <string.h>
int main() 
{ 
	char s[100], b[100];int i, j = 0, k = 0, t[50], flag = 0;unsigned int c=0, a[100] = { 0 };
	gets(s);
	for (i = 0;s[i] != '\0';i++) {
			if (s[i] <= '9' && s[i] >= '0') {
				if(flag==0){
				a[j] = s[i] - '0';
				j++;
				flag = 1;
			}
				else if (flag == 1) {
					a[j-1] = a[j - 1] * 10 + s[i] - '0';
				}
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'||s[i]=='=') {
			b[k] = s[i];
			k++;
			flag = 0;
		}
	}
	for (i = 0;i <= k;i++) {
		if (b[i] == '*' ) {
			a[i + 1] = a[i] * a[i + 1];
		}
		else if (b[i] == '/') {
			a[i + 1] = a[i] / a[i + 1];
		}
		else if (b[i] == '+' || b[i] == '-'||b[i]=='=') {
			if (flag != 0) {
				if (flag == 1) {
					c = c + a[i];
				}
				else if (flag == 2) {
					c = c - a[i];
				}
			}				
			if (flag == 0) {
				c = a[i];
			}
				if (b[i] == '+') {
					flag=1;
				}
				else if(b[i]=='-'){
					flag=2;
				}

		}
	}
	if (flag == 0) {
		printf("%d", a[k - 1]);
	}
	else
	{
		printf("%d", c);
	}
	return 0;
}



