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
                num[c+1] = num[c] * num[c+1]; // @@ [Incorrect operand order: should be `num[c] *= num[c+1]` but logic fails because previous numbers may have been zeroed incorrectly. Also, accessing `t[c-1]` when `c=0` leads to out-of-bounds read.]
                num[c]=0;
                if(t[c-1]=='+') // @@ [When c=0, t[-1] is accessed, which is undefined behavior and likely causes runtime crash or incorrect logic.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same issues as multiplication: wrong accumulation logic and potential division by zero not handled (though problem says valid input). Also, operand order may be inverted due to prior zeroing.]
                num [c]=0;
                if(t[c-1]=='+') // @@ [Again, t[c-1] when c=0 is invalid access.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound `j+1` may exceed allocated meaningful data in `num` and `t`, leading to reading uninitialized or zeroed values, causing incorrect result. Should loop only up to number of operators `i`.]
        switch(t[c]) {
            case '+':
                sum = sum + num[c+1];
                break;
            case '-':
                sum = sum - num[c+1];
                break;
            default:
                break;
        }
    }
    printf("%d",sum);

    return 0;
}