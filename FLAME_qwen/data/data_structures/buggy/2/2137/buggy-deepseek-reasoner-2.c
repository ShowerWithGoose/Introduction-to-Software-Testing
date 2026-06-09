#include <stdio.h> // @@ 
#include <stdlib.h> // @@ 
#include <string.h> // @@ 
#include <math.h> // @@ 
char *blank(char []); // @@ 
int getnum(char[], int, int); // @@ 

int main() { // @@ 
    char s[100]; // @@ 
    gets(s); // @@ 不安全且未实现计算功能
    puts(s); // @@ 应输出计算结果，而非直接输出输入字符串


    return 0; // @@ 
} // @@ 


char *blank(char s[]) { // @@ 
    char *newStr; // @@ 
    int i, j = 0; // @@ 

    newStr = (char *)malloc(strlen(s) + 1); // @@ 
    for (i = 0; s[i] != '\0'; i++) { // @@ 
        if (s[i] != ' ') { // @@ 
            newStr[j++] = s[i]; // @@ 
        } // @@ 
    } // @@ 
    newStr[j] = '\0'; // @@ 

    return newStr; // @@ 
} // @@ 

int getnum(char s[], int p, int q) { // @@ 

    int w, sum = 0; // @@ 
    if (p == 0) { // @@ 
        w = q; // @@ 
        for (int i = 0; i < w; i++) // @@ 在C89中不允许在for循环内声明变量，导致编译错误
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ 
    } else { // @@ 
        w = q - p - 1; // @@ 
        for (int i = 0; i < w; i++) // @@ 同上，C89编译错误
            sum += (s[q - 1 - i] - '0' ) * pow(10, i); // @@ 
    } // @@ 
    return sum; // @@ 
} // @@