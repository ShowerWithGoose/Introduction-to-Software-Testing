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
                if(c > 0 && t[c-1]=='+') // @@ [Added boundary check c > 0 to prevent accessing t[-1] which causes undefined behavior. Also, the logic of replacing operator with +/- is flawed for chained operations but primarily the crash/OOB access is here.]
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
    for(int c=0; c<=j+1; c++) { // @@ [The loop bound j+1 is likely incorrect and may access out of bounds or miss operators. The number of operators is i. The indices in t correspond to 0..i-1. Accessing t[c] where c can go up to j+1 (which is roughly number of operands + 1) is dangerous. However, the primary logical error causing Wrong Answer in this specific "shifting" algorithm is that when an operation is performed, the operator at t[c] should ideally be neutralized or handled so it isn't processed again as a standalone operator in the second pass, OR the second pass should only look at original +/-. But here, the code tries to propagate +/-. The real issue for WA on `24 / 4 / 3 / 2 * 2 * 3 * 4` is that the first pass processes left-to-right. 
    // Let's trace: 
    // nums: 24, 4, 3, 2, 2, 3, 4
    // ops: /, /, /, *, *, *
    // c=0: t[0]='/'. num[1] = 24/4 = 6. num[0]=0. t[-1] accessed (UB).
    // c=1: t[1]='/'. num[2] = 6/3 = 2. num[1]=0. t[0] is now '/' (not + or -), so no change.
    // c=2: t[2]='/'. num[3] = 2/2 = 1. num[2]=0. t[1] is '/', no change.
    // c=3: t[3]='*'. num[4] = 1*2 = 2. num[3]=0. t[2] is '/', no change.
    // c=4: t[4]='*'. num[5] = 2*3 = 6. num[4]=0. t[3] is '*', no change.
    // c=5: t[5]='*'. num[6] = 6*4 = 24. num[5]=0. t[4] is '*', no change.
    // After loop: num = [0, 0, 0, 0, 0, 0, 24]. t = ['/', '/', '/', '*', '*', '*'].
    // Sum = num[0] = 0.
    // Second loop c=0 to j+1. t[0] is '/'. Switch default.
    // t[1] is '/'. Default.
    // ...
    // Sum remains 0.
    // The error is that the result accumulates in the LAST number of the chain, but sum is initialized to num[0] which was zeroed out.
    // The algorithm fails to carry over the result of the continuous multiplication/division chain to the final summation correctly if the chain starts at the beginning.
    // Specifically, `sum = num[0]` is wrong because num[0] might have been zeroed out during the first pass if it was part of a * or / operation.
    ]
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