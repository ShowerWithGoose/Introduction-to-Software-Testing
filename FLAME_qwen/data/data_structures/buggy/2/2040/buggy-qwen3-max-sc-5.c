#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and may cause compilation errors with modern compilers. Use `fgets` instead.]
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
                num[c+1] = num[c] * num[c+1]; // @@ [Incorrect operand order: should be `num[c] = num[c] * num[c+1]` and then zero out `num[c+1]`, not the other way around. Also, this logic fails when multiple * or / are chained.]
                num[c]=0;
                if(t[c-1]=='+')
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same issue as above: incorrect assignment direction. Should update `num[c]`, not `num[c+1]`. Also, integer division is correct per spec, but logic flow is broken.]
                num [c]=0;
                if(t[c-1]=='+')
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound is too large: `j` counts numbers, so valid indices are up to `j-1`; accessing `num[c+1]` when `c` goes up to `j+1` causes out-of-bounds access. Should be `c < j` or similar.]
        switch(t[c]) {
            case '+':
                sum = sum + num[c+1]; // @@ [May read uninitialized or zeroed values due to earlier incorrect handling of operator precedence and array updates.]
                break;
            case '-':
                sum = sum - num[c+1]; // @@ [Same issue as above.]
                break;
            default:
                break;
        }
    }
    printf("%d",sum);

    return 0;
}