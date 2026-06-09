#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[1028], fir[1028], type[1028], ptype[1028];
int num[1028], pnum[1028];

int main() {
    int i,j,k,l;
    int length;
    fgets(s,1028,stdin);
    for(i=0,j=0;i<strlen(s);i++){
        if(s[i] != ' ')
            fir[j++] = s[i];
    }
    for (i=0,j=0,k=0,l=0;i<strlen(fir);i++,j++) {
        if (fir[i] == '+' || fir[i] == '-' || fir[i] == '*' || fir[i] == '/' ||fir[i] == '=')
            type[k++] = fir[i];
        if (fir[i] >= 48 && fir[i] <= 57) {
            for (length = 1; length < 11; length++) {
                if (fir[i + length] >= 48 && fir[i + length] <= 57)
                    continue;
                int n=1,numb=0,w;
                for (w = length; w > 0; w--) {
                    numb += (fir[i + w - 1] - '0') * n;
                    n *= 10;
                }
                num[l++] = numb;
                i += length - 1;
                break;
                if (fir[i + length] < 48 || fir[i + length] > 57)
                    break;
            }
        }
    }
    for (int i = 0, j = 0; i < strlen(type) + 1; i++) {
        if (type[i] == '+' || type[i] == '-' || type[i] == '=') {
            pnum[j] = num[i];
            ptype[j] = type[i];
            j++;
        }
        if (type[i] == '*') {
            num[i + 1] *= num[i];
        }
        if (type[i] == '/') {
            num[i + 1] = num[i] / num[i + 1];
        }
    }
    int put = pnum[0];
    for (int i = 0; i < strlen(ptype); i++) {
        if (ptype[i] == '+') {
            put += pnum[i + 1];
        }
        if (ptype[i] == '-') {
            put -= pnum[i + 1];
        }
    }
    printf("%d",put);
    return 0;
}

