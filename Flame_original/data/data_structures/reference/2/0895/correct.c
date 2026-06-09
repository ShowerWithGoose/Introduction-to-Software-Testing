#include <stdio.h>
#include <string.h>
char s[1028], fir[1028], type[1028], pmtype[2018];
int numb[1028], pmnumb[1028];
 
int main() {
    fgets(s, 1028, stdin);
    for (int i = 0, j = 0; i < strlen(s); i++) {
        if (s[i] != ' ')
            fir[j++] = s[i];
    } // printf("%s",fir);
    for (int i = 0, j = 0, k = 0, l = 0; i < strlen(fir); i++, j++) {
        if (fir[i] == '+' || fir[i] == '-' || fir[i] == '*' || fir[i] == '/' ||
            fir[i] == '=')
            type[k++] = fir[i];
        if (fir[i] >= 48 && fir[i] <= 57) {
            for (int length = 1; length < 11; length++) {
                if (fir[i + length] >= 48 && fir[i + length] <= 57)
                    continue;
                int n = 1, num = 0, w;
                for (w = length; w > 0; w--) {
                    num += (fir[i + w - 1] - '0') * n;
                    n *= 10;
                }
                numb[l++] = num;
                i += length - 1;
                break;
                if (fir[i + length] < 48 || fir[i + length] > 57)
                    break;
            }
        }
    }
  
 
    for (int i = 0, j = 0; i < strlen(type) + 1; i++) {
        if (type[i] == '+' || type[i] == '-' || type[i] == '=') {
            pmnumb[j] = numb[i];
            pmtype[j] = type[i];
            j++;
        }
        if (type[i] == '*') {
            numb[i + 1] *= numb[i];
        }
        if (type[i] == '/') {
            numb[i + 1] = numb[i] / numb[i + 1];
        }
    }
    int put = pmnumb[0];
    for (int i = 0; i < strlen(pmtype); i++) {
        if (pmtype[i] == '+') {
            put += pmnumb[i + 1];
        }
        if (pmtype[i] == '-') {
            put -= pmnumb[i + 1];
        }
    }
    printf("%d", put);
    return 0;

}

