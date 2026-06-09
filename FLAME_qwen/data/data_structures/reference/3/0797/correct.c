#include <stdio.h>

int main() {
    char s[200];
    gets(s);
    int index = 0;
    char *dot, *first;
    first = s;
    dot = s;
    while(*dot !='.')
        dot++;
    if(dot - first == 1) {
        if(*first != '0') {
            printf("%se0\n", s);
            return 0;
        }
        else {
            char *first_num;
            first_num = dot + 1;
            while(*first_num == '0')
                first_num++;
            index = first_num - dot;
            if(*(first_num+1)!='\0') {
                printf("%c.", *first_num);
                printf("%se-%d", dot+index+1, index);
                return 0;
            }
            else {
                printf("%ce-%d", *first_num, index);
                return 0;
            }
        }
    }
    else {
        index = dot - first - 1;
        printf("%c.", *first);
        char *i;
        for(i = first+1; i != dot; i++)
            printf("%c", *i);
        printf("%se%d", i+1, index);
        return 0;
    }
}



