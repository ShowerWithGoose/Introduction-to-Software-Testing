#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error if compiler enforces secure functions. Also, `gets` was removed in C11 standard.]
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
                num[c+1] = num[c] * num[c+1]; // @@ [Incorrect operand order: should use previous non-zero number, but `num[c]` may have been zeroed out already or not represent the correct left operand due to prior operations.]
                num[c]=0;
                if(t[c-1]=='+') // @@ [Accessing `t[c-1]` when `c=0` leads to out-of-bounds read (undefined behavior).]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1]; // @@ [Same operand order issue as multiplication; also integer division is required but logic fails due to incorrect parsing.]
                num [c]=0;
                if(t[c-1]=='+') // @@ [Same out-of-bounds access when `c=0`.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound `j+1` may exceed array bounds of `num` and `t`, leading to undefined behavior. Should be `c < i` or similar based on operator count.]
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