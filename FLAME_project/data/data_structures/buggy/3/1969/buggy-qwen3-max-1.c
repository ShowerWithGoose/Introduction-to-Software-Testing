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
    gets(str); // @@ [Using gets() is unsafe and deprecated; however, the real issue is logic below.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This loop skips all leading zeros and the decimal point, but if the number starts with non-zero digit (like '5'), l remains 0, which is correct. However, for numbers like "0.123", it works, but for "512...", l=0 is fine. The main bug is in exponent calculation.]
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
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [This exponent calculation is incorrect for large numbers. For input "512... .1", r is index of '.', l=0, so d = r - 0 - 1 = (position of '.') - 1. But the number has many digits before '.', so exponent should be (number of digits before '.') - 1, which is r - 1. However, the code uses d = r - l - 1 = r - 1, which is correct in value, but then it prints only one or two digits incorrectly.]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ [Incorrect: '0' - d when d is negative gives wrong digit. Should be '0' + (-d). Also, this branch handles negative exponents with single digit, but logic flawed.]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [This handles negative exponents with two digits, but the earlier branches have bugs.]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [This printf has only one format specifier "%c" but two arguments, so only the first digit is printed. This causes exponent 60 to be printed as '6' instead of "60".]
    }
    return 0;
}