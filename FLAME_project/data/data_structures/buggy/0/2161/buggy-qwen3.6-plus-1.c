#include <stdio.h>
#include <string.h>

int main() {
    int k = 1;
    char a[200], b[200];
    scanf("%s", a);
    b[0] = a[0];
    for (int i = 1; i < strlen(a); i++) {
        if (a[i] == '-') {
            if (a[i - 1] >= 'a' && a[i + 1] <= 'z' && a[i - 1] < a[i + 1]) // @@ The condition checks a[i+1] but does not ensure a[i-1] is lowercase, and more importantly, the loop body is missing braces or proper structure causing syntax error with the following else-if. Also, logic error: it doesn't check if a[i-1] is actually lowercase properly in conjunction with range. But primarily, the syntax error is due to missing braces for the if block containing the for loop, making the subsequent else-if dangling or syntactically invalid in this context.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= 'A' && a[i + 1] <= 'Z' && a[i - 1] < a[i + 1]) // @@ Syntax Error: 'else if' cannot follow a for loop directly without braces enclosing the for loop as part of the preceding if statement's body. The previous if statement's body is just the for loop, but without braces, the association is ambiguous or invalid when followed by else-if.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else if (a[i - 1] >= '0' && a[i + 1] <= '9' && a[i - 1] < a[i + 1]) // @@ Syntax Error: Same as above, dangling else-if.
                for (int j = a[i - 1] + 1; j < a[i + 1]; j++, k++) {
                    b[k] = j;
                } else {
                b[k] = a[i];
                k++;
            }

        } else {
            b[k] = a[i];
            k++;
        }
    }

    printf("%s", b);
}