//
//  main.c
//  2
//
//  Created by  on 2022/5/12.
//
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int calculate(char* s) {
    int n = strlen(s);
    int stk[n], top = 0;
    char preSign = '+';
    int num = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk[top++] = num;
                    break;
                case '-':
                    stk[top++] = -num;
                    break;
                case '*':
                    stk[top - 1] *= num;
                    break;
                default:
                    stk[top - 1] /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    int ret = 0;
    for (int i = 0; i < top; i++) {
        ret += stk[i];
    }
    return ret;
}

int main()
{
 char s[2000];
 gets(s);
 s[strlen(s)-1]='\0';
 printf("%d\n",calculate(s));
 return 0;
} 

