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
                num[c]=0; // @@ [Setting the left operand to zero destroys the intermediate result; for a chain of * and /, the final result ends up in num[i] and num[0] becomes 0, leading to sum=0 later.]
                if(t[c-1]=='+') // @@ [When c==0, t[c-1] accesses out-of-bounds memory.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            case '/':
                num[c+1] = num[c] / num[c+1];
                num [c]=0; // @@ [Same issue as above: zeroing the left operand loses the accumulated value.]
                if(t[c-1]=='+') // @@ [Same out-of-bounds access when c==0.]
                    t[c]='+';
                else if(t[c-1]=='-')
                    t[c]='-';
                break;
            default:
                break;
        }
    }
    sum = num[0]; // @@ [For expressions with only * and /, num[0] is set to 0 in the previous loop; the correct result is stored in num[i], not num[0]. This line causes sum to be 0.]
    for(int c=0; c<=j+1; c++) { // @@ [Loop bound is too large; after parsing, j is the number of numbers, so c goes beyond array indices for t and num.]
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