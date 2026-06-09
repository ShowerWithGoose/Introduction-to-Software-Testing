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
                if(t[c-1]=='+') // @@ Error: out-of-bounds access when c==0; t[-1] is undefined.
                    t[c]='+';
                else if(t[c-1]=='-') // @@ Error: out-of-bounds access when c==0; t[-1] is undefined.
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1];
                num [c]=0;
                if(t[c-1]=='+') // @@ Error: out-of-bounds access when c==0; t[-1] is undefined.
                    t[c]='+';
                else if(t[c-1]=='-') // @@ Error: out-of-bounds access when c==0; t[-1] is undefined.
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0];
    for(int c=0; c<=j+1; c++) { // @@ Error: loop condition should be c < j; current condition causes out-of-bounds access for t and num.
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