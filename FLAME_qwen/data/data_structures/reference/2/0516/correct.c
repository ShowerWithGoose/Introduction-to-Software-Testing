#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
	char s[1005];
	gets (s);
	int i; 
	int len = strlen (s);
	for (i = 0; i < len; i ++) {
		if (s[i] == ' ') {
			int k;
			for(k = i; k < len - 1; k ++) {
				s[k] = s[k + 1];
			}				
			s[len - 1] = '\0';
			len -= 1;
		}
	}
	
	int k;
	int total = 0;
	int mark1 = 0, mark2 = 0;
	int x[105] = {0};
	int number[105] = {0}; 			
	int num = 0, num2 = 0; 
	char sym[105];
	for (k = 0; k < len ; k ++) {
		if(s[k] == '+' || s[k] == '-' || s[k] == '*' || s[k] == '/' || s[k] == '=') {
			sym[num2] = s[k];
			num2 ++;
			char tran[105] = {'\0'};
			mark2 = k;
			int mark3 = mark2 - mark1;
			int e;
			for (e = 0; e < mark3 ; e ++) {
				tran[e] = s[mark1 + e];
			}
			x[num] = atoi(tran);
			num ++;
			mark1 = mark2 + 1;
		}
	}
	num -= 1;
	num2 -= 2;	
	int z;
	for (z = 0; z <= num2; z ++) {
		if (sym[z] == '*') {
			int y;
			for (y = z; y <= num2 - 1; y ++) {
				sym[y] = sym[y + 1];
			}
			sym[num2] == '\0';
			x[z] *= x[z + 1];
			int l;
			for (l = z + 1; l <= num - 1; l ++) {
				x[l] = x[l + 1];
			}
			x[num] = 0;
			num -= 1;
			num2 -= 1;
			z -= 1;
		}
		if (sym[z] == '/') {
			int y1;
			for (y1 = z; y1 <= num2 - 1; y1 ++) {
				sym[y1] = sym[y1 + 1];
			}
			sym[num2] == '\0';
			x[z] /= x[z + 1];
			int l;
			for (l = z + 1; l <= num - 1; l ++) {
				x[l] = x[l + 1];
			}
			x[num] = 0;
			num -= 1;
			num2 -= 1;
			z -= 1;
		}		
	}
	int g;
	for (g = 0; g <= num2; g ++) {
		if (sym[g] == '-') {
			int y;
			for (y = g; y <= num2 - 1; y ++) {
				sym[y] = sym[y + 1];
			}
			sym[num2] == '\0';
			x[g] -= x[g + 1];
			int l;
			for (l = g + 1; l <= num - 1; l ++) {
				x[l] = x[l + 1];
			}
			x[num] = 0;
			num -= 1;
			num2 -= 1;
			g -= 1;
		}
	}
	int totnum;
	for (totnum = 0; totnum <= num; totnum ++) {
		total += x[totnum];
	}
	printf("%d", total);
	return 0;
}

