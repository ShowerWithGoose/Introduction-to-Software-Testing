#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, it reads the whole line including spaces, but the parsing logic below does not correctly handle multi-digit numbers separated by spaces because it resets `num[j]` only when encountering operators, not when transitioning from space to digit.]
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
                num[c+1] = num[c] * num[c+1]; // @@ [This overwrites `num[c+1]` with the product of `num[c]` and `num[c+1]`, but `num[c]` might have already been zeroed out in a previous operation or never set correctly due to incorrect tokenization. Also, the algorithm assumes left-to-right evaluation without respecting operator precedence properly across the entire expression.]
                num[c]=0;
                if(t[c-1]=='+')
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same issue as multiplication: incorrect handling of operand indices and potential division by zero or use of zeroed-out values. Also, integer division is required, but the main problem is operand misalignment.]
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
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound `c<=j+1` may access `t` and `num` out of bounds. `j` is the count of numbers, so valid indices for `num` are `0..j-1`, and for `t` are `0..i-1`. This can lead to reading garbage values.]
        switch(t[c]) {
            case '+':
                sum = sum + num[c+1]; // @@ [If `c+1 >= j`, `num[c+1]` is uninitialized (zeroed initially but not necessarily part of the expression), leading to wrong results.]
                break;
            case '-':
                sum = sum - num[c+1]; // @@ [Same out-of-bound access issue as above.]
                break;
            default:
                break;
        }
    }
    printf("%d",sum);

    return 0;
}