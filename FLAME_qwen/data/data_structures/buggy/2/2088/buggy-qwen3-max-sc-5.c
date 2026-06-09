#include <stdio.h>
#include <string.h>
char c[10010];
int a[10010], l, ans, b, n;

int search(int x) {
    int ans0 = a[x];
    if (a[x - 3] == '+' || a[x - 3] == '-') {
        if (a[x - 1] == '*')
            return ans0 * a[x - 2];
        else if (a[x - 1] == '/')
            //printf("=%d=", a[x - 2] / ans0);
            return  a[x - 2] / ans0 ;
    } else if (a[x - 3] == '*' || a[x - 3] == '/') {
        n += 2;
        //printf("%d,", n);
        if (a[x - 1] == '*')
            return ans0 * search(x - 2);
        else if (a[x - 1] == '/')
            return  search(x - 2) / ans0 ;
    }
    return ans0; // @@ [Missing return statement in non-void function: control reaches end of non-void function]
}

int main() {
    gets(c); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also not available in C11+ standard libraries]
    l = strlen(c);
    int j = 0;
    for (int i = 0; i < l; i++) {
        if (c[i] != ' ')
            c[j++] = c[i];
    }
    c[j] = '\0';
    //printf("%s\n", c);
    l = j;
    j = 1;
    for (int i = 0; i < l; i++) {
        if (c[i] >= '0' && c[i] <= '9') {
            a[j] *= 10; // @@ [Uninitialized array element a[j] used; should initialize a[j] to 0 before accumulating digits]
            a[j] += c[i] - '0';
        } else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
            j++;
            a[j] = c[i];
            j++;
        }
    }
    //for (int i = 1; i <= j; i++) {
    //    printf("%d,", a[i]);
    //}
    b = a[j];
    for (int i = j; i > 2; i -= 2) {
        //printf(":%d:", n);
        if (a[i - 1] == '*' || a[i - 1] == '/') {
            n += 2;
            b = search(i);
            //printf("=%d=", b);
            i -= (n - 2);

        } else if (a[i - 1] == '+') {
            ans += n ? b : a[i];
            n = 0;
        } else if (a[i - 1] == '-') {
            ans -= n ? b : a[i];
            n = 0;
        }
        //printf("%d,%d\n", i, ans);
    }
    ans += n ? b : a[1];
    printf("%d", ans);
    return 0;
}
//1+2*3+1/3=