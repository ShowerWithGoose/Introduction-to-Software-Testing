#include <stdio.h>
#include <string.h>
char c[10010];
int a[10010], l, ans, b, n;

int search(int x) {
    int ans0 = a[x];
    if (a[x - 3] == '+' || a[x - 3] == '-') { // @@ [Potential out-of-bounds for x<3; missing base case leads to undefined behavior]
        if (a[x - 1] == '*')
            return ans0 * a[x - 2];
        else if (a[x - 1] == '/')
            //printf("=%d=", a[x - 2] / ans0);
            return  a[x - 2] / ans0 ;
    } else if (a[x - 3] == '*' || a[x - 3] == '/') { // @@ [Missing base case when x-3 is not an operator; causes fall-through]
        n += 2; // @@ [Modifies global variable n, causing unpredictable loop adjustments and incorrect accumulation]
        //printf("%d,", n);
        if (a[x - 1] == '*')
            return ans0 * search(x - 2); // @@ [Incorrect associativity; should evaluate left-to-right, not right-to-left]
        else if (a[x - 1] == '/')
            return  search(x - 2) / ans0 ; // @@ [Incorrect associativity for division; left-to-right required]
    }
} // @@ [Missing return statement for base case; leads to undefined behavior (returns 0)]

int main() {
    gets(c);
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
            a[j] *= 10;
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
            n += 2; // @@ [Modifies global n, causing side effects]
            b = search(i); // @@ [Uses flawed search function that may return 0]
            i -= (n - 2); // @@ [Incorrect index manipulation; can cause out-of-bounds or infinite loop]
        } else if (a[i - 1] == '+') {
            ans += n ? b : a[i]; // @@ [Incorrect handling of addition due to right-to-left processing and use of global n]
            n = 0;
        } else if (a[i - 1] == '-') {
            ans -= n ? b : a[i]; // @@ [Incorrect handling of subtraction; left-to-right required]
            n = 0;
        }
        //printf("%d,%d\n", i, ans);
    }
    ans += n ? b : a[1]; // @@ [Uses global n which may not be reset, leading to wrong final accumulation]
    printf("%d", ans);
    return 0;
}