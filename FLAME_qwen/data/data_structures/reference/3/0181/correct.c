#include <stdio.h>
#include<stdlib.h>
char c[1000];
int i,k;
char j;
void delspace(char s[], char c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
void print(char c[]) {
    int i = 0;
    while (c[i] != '\0') {
        printf("%c", c[i++]);
    }
}
void func1(char c[]) {
    int i = 2, j;
    while (c[i++] == '0');
    i--;
    j = i;
    if (c[i + 1] == '\0') {
        printf("%ce-%d", c[i], j - 1);
        return;
    }
    printf("%c.", c[i++]);
    while (c[i] != '\0')
        printf("%c", c[i++]);
    printf("e-%d", j - 1);
}
void func2(char c[]) {
    int i=1, j;
    printf("%c.", c[0]);
    while (c[i] != '.'&&c[i]!='\0')
        printf("%c", c[i++]);
    if (c[i] == '.') {
        j = i;
        i++;
    }
    while (c[i] != '.' && c[i] != '\0')
        printf("%c", c[i++]);
    printf("e%d", j-1);
}
int main()
{
    gets(c);
    if (c[0] == '0') {
        func1(c);
    }
    else if (c[1] == '.') {
        print(c);
        printf("e0");
    }
    else {
        func2(c);
    }


    return 0;
}



