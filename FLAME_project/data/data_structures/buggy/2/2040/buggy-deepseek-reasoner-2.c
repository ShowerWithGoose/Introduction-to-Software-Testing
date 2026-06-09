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
                j++; // @@ j is incremented unnecessarily; it makes j one more than the number of operators, leading to an incorrect loop bound later.
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
                if(t[c-1]=='+') // @@ When c==0, t[-1] is accessed, which is out of bounds and leads to undefined behavior.
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1];
                num [c]=0;
                if(t[c-1]=='+') // @@ Same issue: out-of-bounds access when c==0.
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0]; // @@ After multiplication/division, num[0] has been set to 0, so sum is incorrectly initialized to 0. The final result is stored in later num entries.
    for(int c=0; c<=j+1; c++) { // @@ Loop bound (j+1) is too large; j was inflated by the '=' case, and the loop accesses out-of-bounds indices in t and num. Also, it does not handle the last number when there are no '+' or '-' operators.
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