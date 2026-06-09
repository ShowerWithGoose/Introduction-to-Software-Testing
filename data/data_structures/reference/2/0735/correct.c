#include<stdio.h>
#include<string.h>
#include<ctype.h>
int f(char* s) {
    int n = strlen(s);
    int m[n], t = 0;
    char fuhao = '+';
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (fuhao) {
                case '+':
                    m[t++] = num;
                    break;
                case '-':
                    m[t++] = -num;
                    break;
                case '*':
                    m[t - 1] *= num;
                    break;
                default:
                    m[t - 1] /= num;
            }
            fuhao = s[i];
            num = 0;
        }
    }
    int result = 0;
    for (int i = 0; i < t; i++) {
        result += m[i];
    }
    return result;
}

int main() 
{ 
	char s[2000];
	gets(s);
	s[strlen(s)-1]='\0';
	printf("%d\n",f(s)); 
	return 0; 
} 



