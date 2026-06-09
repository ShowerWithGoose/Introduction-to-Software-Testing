#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[200];
    int i;
    gets(s);
    int n = strlen(s);
    int num = 0, inte[n], top = -1, res = 0;
    char sign = '+';
    for ( i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (int) (s[i] - '0');
        }
        if ((s[i] != ' ' && !isdigit(s[i])) || i == n - 1) {
            if(sign=='+'){
                    top++;
                    inte[top] = num;
                }
            if(sign=='-'){
                    top++;
                    inte[top] = -num;
                }
			if(sign=='*'){
                    inte[top] *= num;
                }
			if(sign=='/'){
                     inte[top] /= num;
                }
			sign = s[i];
            num = 0;
            }
            
        }
    for ( i = 0; i <= top; i++) {
        res += inte[i];
    }
    printf("%d",res);
    return 0;
}

