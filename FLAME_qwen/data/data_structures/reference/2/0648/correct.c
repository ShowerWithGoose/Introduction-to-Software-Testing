#include <string.h>
#include <stdio.h>
char a[1028], b[1028], c[1028], d[1028];
int e[1028], f[1028];
int main() {
    fgets(a, 1028, stdin);
    for (int i = 0, j = 0; i < strlen(a); i++) 
    {
        if (a[i] != ' ')
            b[j++] = a[i];
    }
    for (int i = 0, j = 0, k = 0, l = 0; i < strlen(b); i++, j++) 
    {
        if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' ||b[i] == '=')
            c[k++] = b[i];
        if (b[i] >= 48 && b[i] <= 57) {
            for (int length = 1; length < 11; length++) 
            {
                if (b[i + length] >= 48 && b[i + length] <= 57)
                    continue;
                int n = 1, num = 0, w;
                for (w = length; w > 0; w--) 
                {
                    num += (b[i + w - 1] - '0') * n;
                    n *= 10;
                }
                e[l++] = num;
                i += length - 1;
                break;
                if (b[i + length] < 48 || b[i + length] > 57)
                    break;
            }
        }
    }
    for (int i = 0, j = 0; i < strlen(c) + 1; i++) 
    {
        if (c[i] == '+' || c[i] == '-' || c[i] == '=') 
        {
            f[j] = e[i];
            d[j] = c[i];
            j++;
        }
        if (c[i] == '*') 
        {
            e[i + 1] *= e[i];
        }
        if (c[i] == '/') 
        {
            e[i + 1] = e[i] / e[i + 1];
        }
    }
    int put = f[0];
    for (int i = 0; i < strlen(d); i++) 
    {
        if (d[i] == '+') 
        {
            put += f[i + 1];
        }
        if (d[i] == '-') 
        {
            put -= f[i + 1];
        }
    }
    printf("%d", put);
    return 0;
}
