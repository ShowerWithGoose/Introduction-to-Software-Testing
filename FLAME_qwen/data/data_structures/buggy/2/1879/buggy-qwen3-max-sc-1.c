#include <stdio.h>
#include <string.h>
char a[1000];//×Ö·û
int b[1000];//Êý×Ö

int main() {
    int i = 1;
    a[0] = '+';
    b[0] = 0;
    scanf("%d", &b[i]);
    scanf(" %c", &a[i]);
    while (a[i] != '=') {
        i++;
        scanf("%d", &b[i]);
        scanf(" %c", &a[i]);
    }
    int n = i;
    int j = 0, x = b[2], result = b[1]; // @@ [x is initialized to b[2], but if the expression has only one number (e.g., "5 ="), b[2] is uninitialized, leading to undefined behavior. Also, result assumes at least one number exists, but indexing starts incorrectly for expressions with only one term.]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j]; // @@ [If the expression ends right after the first number (like "5 ="), then n=1, and this loop may not run, but prior initialization of x = b[2] already caused an issue. Additionally, in cases where multiplication/division chain starts at the last number, b[j+1] may be accessed out of bounds.]
        while (a[j] == '*' || a[j] == '/') {
            if (a[j] == '*')
                x *= b[j + 1]; // @@ [When j is the index of the last operator before '=', b[j+1] accesses beyond valid input data, causing undefined behavior. For example, in "2 * 3 =", when j points to '*', b[j+1] is b[index_of_3], which is okay, but loop condition doesn't ensure j+1 is within bounds. However, more critically, the parsing logic mismatches operand/operator alignment.]
            else
                x /= b[j + 1]; // @@ [Same as above: potential out-of-bounds access to b[j+1].]
            j++;
        }
        if (a[i] == '+')
            result += x;
        else
            result -= x; // @@ [This assumes every term after the first is preceded by '+' or '-', but the initial setup forces a[0]='+', b[0]=0, and starts processing from i=0, which may double-count or misalign terms. For instance, in "5 =", it tries to process a[0]='+' and x=b[1]=5, which works, but in "5 - 1 =", it sets result = b[1]=5, then subtracts x (which becomes b[2]=1), yielding 4 — correct. However, the real flaw is that the loop structure doesn't correctly handle the count of numbers vs operators, especially when there's only one number. Also, the initial assignment 'result = b[1]' fails if input has no numbers before '=' (though problem states expression is valid). But more critically, the indexing assumes at least two numbers exist when initializing x = b[2].]
        i = j;

    }
    printf("%d", result);
}