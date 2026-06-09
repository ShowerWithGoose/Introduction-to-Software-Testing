#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
int main(){
    char a[10000], b[10000];
    sf("%s", a);
    int i, j = 0, k;
    for (i = 0; i <= strlen(a) - 1; i++) {
        if (a[i] != '-') {
            b[j++] = a[i];
        } else if (a[i] == '-') {
            if ((((a[i-1] >= 'a' && a[i-1] <= 'z') && (a[i+1] >= 'a' && a[i+1] <= 'z')) || 
                 ((a[i-1] >= 'A' && a[i-1] <= 'Z') && (a[i+1] >= 'A' && a[i+1] <= 'Z')) || 
                 ((a[i-1] >= '0' && a[i-1] <= '9') && (a[i+1] >= '0' && a[i+1] <= '9'))) && 
                a[i-1] < a[i+1]) {
                for (k = a[i-1] + 1; k < a[i+1]; k++) {
                    b[j++] = k;
                }
            } else {
                b[j++] = '-';
            }
        }
    }
    b[j] = '\0';
    printf("%s", b);
    return 0;
}