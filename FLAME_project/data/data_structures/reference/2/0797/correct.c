#include <stdio.h>
#include <string.h>

void squeez_space(char s[]) {
    int i, j;
    for(i = j = 0; s[i]!='\0'; i++)
        if(s[i]!=' ')
            s[j++] = s[i];
    s[j] = '\0';
}
int multi_div(char *begin, char *over) {
    int num1 = 0, num2 = 0;
    char *q = begin;
    char sign;
    for(q = begin; *q>='0' && *q<='9' && q!=over+1; q++)
        num1 = 10*num1 + *q-'0';

    while(1){
        if(q==over+1)
            return num1;
        sign = *q;
        q++;//skip the * or /
        for(; *q>='0' && *q<='9' && q!=over+1; q++)
            num2 = 10*num2 + *q-'0';
        //printf("num2 = %d\n", num2);
        if(sign=='*')
            num1 = num1*num2;
        if(sign=='/')
            num1 = num1/num2;
        num2 = 0;
    }
}



int main() {
    char s[100];
    gets(s);
    squeez_space(s);
    //printf("s = %s\n", s);
    int out = 0, i = 0;
    char *p, *start, *stop;
    for(p = s; ; p++, i++) {
        if(p!=s && *(p-1)=='=') {
            printf("%d", out);
            return 0;
        }
        //* or /
        if(*(p+1) == '*' || *(p+1) == '/' || *(p+1) == '=' || *(p+1) == '+' || *(p+1) == '-') {
            start = p-i;
            while(1) {
                if(*p=='+' || *p=='-' || *p=='=') {
                    stop = p-1;
                    break;
                }
                else
                    p++;
            }
//            printf("stop - start = %d\n", stop-start);
//            printf("I find a term = %d\n", multi_div(start, stop));
            i = -1;
            if(start!=s && *(start-1)=='-')
                out -= multi_div(start, stop);
            else
                out += multi_div(start, stop);
        }

    }

    //printf("%d", out);
    return 2;
}



