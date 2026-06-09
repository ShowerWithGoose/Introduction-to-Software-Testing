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
    int j = 0, x = b[2], result = b[1]; // @@ [x is initialized to b[2], but if the expression has only one term or starts with operators, b[2] may be uninitialized or incorrect; also, the logic for grouping multiplication/division terms is flawed because it assumes at least two numbers exist before processing]
    for (i = 0, j = 1; i < n;) {
        j = i + 1;
        x = b[j]; // @@ [if j exceeds valid index (e.g., when expression ends), this accesses uninitialized memory; also, the loop condition and indexing do not properly handle the last term]
        while (a[j] == '*' || a[j] == '/') {
            if (a[j] == '*')
                x *= b[j + 1];
            else
                x /= b[j + 1];
            j++; // @@ [j increments without checking bounds; may access beyond array limits or skip correct term boundaries]
        }
        if (a[i] == '+')
            result += x;
        else
            result -= x;
        i = j; // @@ [after processing a group of * and /, i jumps to j, but j points to the operator after the last processed number, causing misalignment in next iteration]

    }
    printf("%d", result);
}