#include <stdio.h>
#include <string.h>
char str[1111], f[1111], t[1111], pmt[1111];
int numb[1111], pmnumb[1111],i,j;
int main() {
	int i,j,k,l;
	fgets(str, 1111, stdin);
	for (i = 0, j = 0; i < strlen(str); i++) {
		if (str[i] != ' ') {
			f[j] = str[i];
			j++;
		}
	}
	for (i = 0, j = 0, k = 0, l = 0; i < strlen(f); i++, j++) {
		if (f[i] == '+' || f[i] == '-' || f[i] == '*' || f[i] == '/' ||f[i] == '=')
			t[k++] = f[i];
		if (f[i] >= 48 && f[i] <= 57) {
			for (int length = 1; length < 11; length++) {
				if (f[i + length] >= 48 && f[i + length] <= 57)
					continue;
				int n = 1, num = 0, w;
				for (w = length; w > 0; w--) {
					num += (f[i + w - 1] - '0') * n;
					n *= 10;
				}
				numb[l] = num;
				l++;
				i += length - 1;
				break;
				if (f[i + length] < 48 || f[i + length] > 57)
					break;
			}
		}
	}
	for (i = 0, j = 0; i <= strlen(t); i++) {
		if (t[i] == '+' || t[i] == '-' || t[i] == '=') {
			pmnumb[j] = numb[i];
			pmt[j] = t[i];
			j++;
		}
		if (t[i] == '/') {
			numb[i + 1] = numb[i] / numb[i + 1];
		}
		if (t[i] == '*') {
			numb[i + 1] *= numb[i];
		}
		
	}
	int put = pmnumb[0];
	for (int i = 0; i < strlen(pmt); i++) {
		if (pmt[i] == '+') {
			put += pmnumb[i + 1];
		}
		if (pmt[i] == '-') {
			put -= pmnumb[i + 1];
		}
	}
	printf("%d", put);
	return 0;
}

