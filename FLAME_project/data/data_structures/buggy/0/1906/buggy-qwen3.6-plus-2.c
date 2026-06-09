#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[1000];
    gets(a);
    int i, j;
    j = 0;
    i = 0;
    while (a[i] != '\0') {
        if (a[i + 1] != '-') {
            b[j] = a[i];
            j++;
            i++;
        } else {
            if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z')) // @@ The condition for checking character types is incorrect. It checks if the start char is in range and end char is in range, but doesn't ensure they are the SAME type (e.g., '0' to 'z' would pass the first part of OR if not careful, but specifically here 'a' >= '0' is true and 'u' <= '9' is false. However, the logic `a[i] >= '0' && a[i+2] <= '9'` allows mixing types if ranges overlap or logic is flawed. More importantly, it fails to strictly enforce that BOTH are digits, BOTH are lower, or BOTH are upper. For example, if a[i]='0' and a[i+2]='z', `a[i]>='0'` is true, `a[i+2]<='9'` is false. But if a[i]='A' and a[i+2]='z', `a[i]>='A'` is true, `a[i+2]<='Z'` is false. The current logic actually accidentally works for type separation due to ASCII values, BUT it misses the check that the second character must also be >= the start of its respective range. E.g., `a[i+2] >= '0'` is missing. Without checking the lower bound of the second character, invalid ranges might pass if only upper bounds are checked against mixed types. Specifically, the requirement is "same type". The condition `(a[i] >= '0' && a[i + 2] <= '9')` does not ensure `a[i+2] >= '0'` nor `a[i] <= '9'`. So '0'-'/' (ASCII 47) might behave unexpectedly or '0'-'9' is fine. But crucially, it doesn't check if `a[i]` and `a[i+2]` are both valid members of the same set properly. A correct check is `(isdigit(a[i]) && isdigit(a[i+2])) || ...`. The existing check `a[i] >= '0' && a[i+2] <= '9'` is insufficient because it doesn't check `a[i] <= '9'` and `a[i+2] >= '0'`.
                    && a[i] < a[i + 2]) {
                b[j] = a[i];
                j++;
                for (; b[j] <= a[i + 2]; j++) // @@ Logic error in loop condition and body. This loop writes to b[j] then increments j. When the loop finishes, b[j] contains the last character written, but the index j has been incremented past it. The next iteration of the outer while loop will overwrite b[j] or continue from there. However, the major issue is that this loop generates characters starting from a[i]+1 up to a[i+2]. It sets b[j] (which is currently uninitialized or garbage if not carefully managed, though here b[j-1] was set previously) based on b[j-1]. Wait, `b[j]` is being written. `b[j-1]` is the previous char. So `b[j] = b[j-1] + 1`. This correctly generates the sequence. However, after the loop, `j` points to the position AFTER the last generated character. The code then does `i = i + 2`. This skips the '-' and the end character. This part seems logically okay for generation, BUT:
                    b[j] = b[j - 1] + 1;
                i = i + 2;
            } else {
                b[j] = a[i];
                j++;
                i++;
            }
        }
    }
    b[j] = '\0';
    printf("%s", b);
    return 0;
}