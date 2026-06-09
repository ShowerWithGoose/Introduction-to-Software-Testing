#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error if compiler enforces secure functions]
    for(int p=0; s[p]!='='; p++) {
        if(s[p]>='0'&&s[p]<='9') {
            num[j] = num[j]*10 + s[p] - '0';
        }
        switch(s[p]) {
            case '+':
                t[i]='+';
                i++;
                j++;
                break;
            case '-':
                t[i]='-';
                i++;
                j++;
                break;
            case '*':
                t[i]='*';
                i++;
                j++;
                break;
            case '/':
                t[i]='/';
                i++;
                j++;
                break;
            case '=':
                j++;
                break;
            default:
                break;
        }
    }
    for(int c=0; c<i; c++) {
        switch(t[c]) {
            case '*':
                num[c+1] = num[c] * num[c+1]; // @@ [Incorrectly uses `num[c]` which may have been zeroed out or not correspond to the correct operand due to flawed parsing logic]
                num[c]=0;
                if(t[c-1]=='+') // @@ [Accesses `t[c-1]` when `c` could be 0, leading to out-of-bounds read (undefined behavior)]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same issue: `num[c]` may not hold the intended left operand due to prior zeroing and incorrect indexing]
                num [c]=0;
                if(t[c-1]=='+') // @@ [Same out-of-bounds access when c == 0]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound `j+1` may exceed valid indices of `t` and `num`, causing out-of-bounds access]
        switch(t[c]) {
            case '+':
                sum = sum + num[c+1]; // @@ [`num[c+1]` may be uninitialized or zero due to earlier overwrites and incorrect parsing]
                break;
            case '-':
                sum = sum - num[c+1]; // @@ [Same issue with potentially invalid `num[c+1]`]
                break;
            default:
                break;
        }
    }
    printf("%d",sum);

    return 0;
}