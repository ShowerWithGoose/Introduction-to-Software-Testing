#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a, b) a > b ? a : b
#define ll long long
#define maxn 1000006
#define inf 0x7fffffff
#define eps 1e-7
/*
long fib(int x){
    switch(x){
        case 0:return 0;
        case 1:
        case 2:return 1;
    }
    return (fib(x-1) + fib(x-2));

}

int main(){
    int x = 6;
    printf("%d", fib(x));
    return 0;
}
*/

/*
int cal(int a, char c, int b){
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    if(c == '+') return a+b;
    if(c == '-') return a-b;
}

int main(){
    int ans = 0;
    char str[1005];
    int len = strlen(str);
    int a[1005];
    int b[1]
    for(int i = 0; i < len; i++){
        if(str[i] == ' '){
            char temp[1005];
            strncpy(temp, str, i);
            strcat(temp, str+i+1);
            strcpy(str, temp);
        }
    }
    str[i+1] = '\0';
    len = strlen(str);
    for(int j = 0; j < len-1; j++){
        if(str[i] >= '0' && str[i] <= '9'){
            ans = 10 * ans + (str[i] - '0');
            if(str[i+1] < '0' && str[i+1] > '9'){
                if
            }
        }
    }
}
*/


int main(){
    char str[105];
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11 onwards), 'gets' has been removed entirely, leading to compilation error if compiler strictly adheres to standard without legacy support.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){ // @@ [If input has no decimal point, this loop runs out of bounds causing undefined behavior or infinite loop; problem states input always has digits before and after decimal, but code doesn't validate presence of '.', so accessing beyond string end is possible.]
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This skips all leading zeros and the decimal point, but if the number starts with non-zero digit (e.g., "123.45"), it won't skip anything, which is okay. However, if the number is like "0.00123", this correctly finds first non-zero. But logic fails when there's no leading zero before decimal (e.g., "1.23") because '.' is skipped incorrectly if encountered early. Also, if string starts with '.', this may misbehave.]
        l++;
    }
    //r = strstr(str, '.') - str[0];
    printf("%c", str[l]);
    if(str[l+1] != '\0'){
        printf(".");
        for(int i = l+1; str[i] != '\0'; i++){
            if(str[i] == '.') continue;
            printf("%c", str[i]);
        }
    }
    printf("e");
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [Incorrect exponent calculation. For example, input "123.45": r=3 (index of '.'), l=0 (first non-zero at '1'), then d = 3 - 0 - 1 = 2 → correct (1.2345e2). But for "0.00123": r=1, l=3 (first non-zero at '1'), d = 1 - 3 = -2, but should be -3 (since 0.00123 = 1.23e-3). So formula is wrong for numbers < 1.]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ [Wrong character conversion: '0' - d when d is negative gives '0' + |d|, but expression is misleading and actually works only if d is negative. However, '0' - (-3) = '0' + 3 = '3', which is correct. But style is confusing. Not a functional error here, but next lines have real bugs.]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [This prints two-digit negative exponent correctly in format, e.g., -12 → "-12", but uses %c for each digit. However, (-d)/10 and (-d)%10 are integers, so adding to '0' gives correct chars. This part is okay.]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [printf format specifier mismatch: using "%c" but providing two arguments. Should be "%c%c". This causes undefined behavior and incorrect output for exponents >=10.]
    }
    return 0;
}