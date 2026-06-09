#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int sum = 0, a, b, c = 1, k=1; // @@ Variable 'a' is uninitialized, which may lead to undefined behavior or compilation errors with strict warning flags.
    char q;

    scanf("%d", &b);

    while (1) {
    out:
        scanf("%c", &q); // @@ Reads whitespace characters (including newlines) which are not filtered, causing 'q' to potentially be '\n' and skip operator logic.
        if (q == ' ') goto out; // @@ Only handles space characters; fails to skip newlines or tabs, leading to incorrect parsing flow.

        if(q=='+'){
            if(k==2)sum+=a*b;
            else if(k==3)
            sum+=a/b; // @@ Missing braces for the multi-line else-if block; while syntactically valid, it is error-prone and can cause logical issues.
            else if(k==1||k==4)sum+=b;
            k=1;a=0;c=1;
        }
        if(q=='-'){
            if(k==2)sum+=a*b;
            else if(k==3)sum+=a/b;
            else if(k==1||k==4)sum+=b;
            k=4;a=0;c=-1;
        }
        if(q=='*'){
            if(k==1 || k==4)a=b;
            else a*=b;
            k=2;c=1;
        }
        if(q=='/'){
            if(k==1 || k==4)a=b;
            else a/=b;
            k=3;c=1;
        }
    if(q=='='){
        if(k==1)sum+=b;
        else if(k==2)sum+=a*b;
        else if(k==3)sum+=a/b;
        else if(k==4)sum+=b;
        else sum+=a;
        break;
    }


        scanf("%d",&b); // @@ Executed unconditionally after operator checks, even when 'q' is whitespace, causing incorrect input consumption and potential infinite loops.
        b=b*c;

    }
    printf("%d", sum);
}