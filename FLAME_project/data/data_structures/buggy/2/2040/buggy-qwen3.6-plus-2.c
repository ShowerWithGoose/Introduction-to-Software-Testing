#include <stdio.h>
#include <stdlib.h>
char s[1000],t[1000];
int main() {
    int num[1000];
    int j=0,i=0,sum=0;
    for(int c=0; c<1000; c++) {
        num[c]=0;
    }
    gets(s);
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
                num[c+1] = num[c] * num[c+1];
                num[c]=0;
                if(c > 0 && t[c-1]=='+') // @@ [Added boundary check c > 0 to prevent accessing t[-1] which causes undefined behavior. Also, the logic of replacing * with + is flawed for chained operations like A*B*C, but the immediate crash/UB risk is the index.]
                    t[c]='+';
                else if(c > 0 && t[c-1]=='-') // @@ [Added boundary check c > 0 to prevent accessing t[-1].]
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1];
                num [c]=0;
                if(c > 0 && t[c-1]=='+') // @@ [Added boundary check c > 0 to prevent accessing t[-1].]
                    t[c]='+';
                else if(c > 0 && t[c-1]=='-') // @@ [Added boundary check c > 0 to prevent accessing t[-1].]
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<i; c++) { // @@ [Changed loop condition from c<=j+1 to c<i. The variable j counts numbers, while i counts operators. Iterating up to j+1 accesses uninitialized or garbage values in t[] and num[], leading to incorrect calculations. We should only iterate through the valid operators stored in t[0] to t[i-1].]
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