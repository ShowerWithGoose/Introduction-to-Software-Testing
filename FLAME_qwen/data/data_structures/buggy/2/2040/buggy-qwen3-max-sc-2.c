#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s); // @@ [Using `gets` is unsafe and deprecated; more critically, the program logic incorrectly increments `j` on every operator and '=' without properly handling multi-digit numbers separated by spaces or correctly aligning operands with operators.]
    for(int p=0; s[p]!='='; p++) {
        if(s[p]>='0'&&s[p]<='9') {
            num[j] = num[j]*10 + s[p] - '0';
        }
        switch(s[p]) {
            case '+':
                t[i]='+';
                i++;
                j++; // @@ [This increments `j` immediately after reading an operator, which causes misalignment between numbers and operators. For example, in "5+3", after reading '5', then '+', it moves to next number slot before reading '3'. But if there are consecutive operators or spaces, this breaks. Also, it doesn't skip non-digit/non-operator characters properly.]
                break;
            case '-':
                t[i]='-';
                i++;
                j++; // @@ [Same issue as above: premature increment of `j` leads to incorrect indexing of `num` array.]
                break;
            case '*':
                t[i]='*';
                i++;
                j++; // @@ [Same issue: `j` should only increment when a new number starts, not when an operator is encountered. This causes operands to be stored in wrong positions.]
                break;
            case '/':
                t[i]='/';
                i++;
                j++; // @@ [Same issue as above.]
                break;
            case '=':
                j++; // @@ [Unnecessary and incorrect: `j` should not be incremented on '=', especially since loop condition stops at '='. This may cause out-of-bounds access later.]
                break;
            default:
                break;
        }
    }
    for(int c=0; c<i; c++) {
        switch(t[c]) {
            case '*':
                num[c+1] = num[c] * num[c+1]; // @@ [This assumes `num[c]` holds the left operand, but due to earlier incorrect `j` management, `num[c]` might be zero or wrong. Also, modifying `num[c+1]` in place disrupts subsequent operations if multiple * or / are present.]
                num[c]=0;
                if(t[c-1]=='+') // @@ [Accessing `t[c-1]` when `c=0` leads to undefined behavior (reading before start of array).]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same issues as multiplication: wrong operand alignment and potential division by zero not handled (though problem says valid input). Also, integer division is correct per spec, but operands may be wrong due to earlier errors.]
                num [c]=0;
                if(t[c-1]=='+') // @@ [Again, `t[c-1]` when `c=0` is invalid access.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound `c <= j+1` likely exceeds valid indices of `t` and `num`. `j` was over-incremented, so `j+1` may be far beyond actual number of operators (`i`) or numbers. Should loop up to `i` or `j-1`, not `j+1`.]
        switch(t[c]) {
            case '+':
                sum = sum + num[c+1]; // @@ [If `c` goes beyond actual operators, `t[c]` is uninitialized, and `num[c+1]` may be zero or garbage. Also, due to earlier zeroing of `num[c]` during * and / processing, some values are lost.]
                break;
            case '-':
                sum = sum - num[c+1]; // @@ [Same issue: accessing potentially invalid or zeroed entries.]
                break;
            default:
                break;
        }
    }
    printf("%d",sum);

    return 0;
}