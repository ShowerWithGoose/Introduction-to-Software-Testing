#include <stdio.h>
#include <string.h>
int main() {
	char s[300],sh[300],op[300],ops[300];
	int numb[300],ns[300];
    gets(s);
    for (int i = 0, j = 0; i < strlen(s); i++) {
        if (s[i] != ' ')
            sh[j++] = s[i];
    } 
    for (int i = 0, j = 0, k = 0, l = 0; i < strlen(sh); i++, j++) {
        if (sh[i] == '+' || sh[i] == '-' || sh[i] == '*' || sh[i] == '/' ||
            sh[i] == '=')
            op[k++] = sh[i];
        if (sh[i] >= '0' && sh[i] <= '9') {
            for (int length = 1; length < 11; length++) {
                if (sh[i + length] >= '0' && sh[i + length] <= '9')
                    continue;
                int n = 1, num = 0, w;
                for (w = length; w > 0; w--) {
                    num += (sh[i + w - 1] - '0') * n;
                    n *= 10;
                }
                numb[l++] = num;
                i += length - 1;
                break;
                if (sh[i + length] < '0' || sh[i + length] > '9')
                    break;
            }
        }
    }
    
 
    for (int i = 0, j = 0; i < strlen(op) + 1; i++) {
        if (op[i] == '+' || op[i] == '-' || op[i] == '=') {
            ns[j] = numb[i];
            ops[j] = op[i];
            j++;
        }
        if (op[i] == '*') {
            numb[i + 1] *= numb[i];
        }
        if (op[i] == '/') {
            numb[i + 1] = numb[i] / numb[i + 1];
        }
    }
    int put = ns[0];
    for (int i = 0; i < strlen(ops); i++) {
        if (ops[i] == '+') {
            put += ns[i + 1];
        }
        if (ops[i] == '-') {
            put -= ns[i + 1];
        }
    }
    printf("%d", put);
    return 0;
}

