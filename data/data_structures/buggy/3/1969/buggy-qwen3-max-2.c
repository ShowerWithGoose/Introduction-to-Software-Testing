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
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that treat warnings as errors.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){ // @@ [If input has no '.', this loop runs out of bounds causing undefined behavior. Problem states input always has digits before and after decimal, but code doesn't validate presence of '.']
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This skips all leading zeros and the decimal point, but if the number starts with non-zero digit, l stops correctly. However, if input is "0.123", l becomes index of '1', which is correct, but logic is fragile.]
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
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [Incorrect exponent calculation. For "123.45", r=3, l=0 → d=2, correct. But for "0.00123", l=4 ('1'), r=1 → d = 1-4 = -3, but should be -3? Actually, exponent should be -3, but formula gives -3, so maybe okay. However, logic is unclear and error-prone.]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ [Incorrect character conversion: '0' - d when d is negative. Example: d = -3 → '0' - (-3) = '0'+3 = '3', so prints "-3" as "-3"? But format is "-%c", so prints "-3", which is correct. However, '0' - d is same as '0' + |d|, but expression is confusing and technically works only for single-digit. But bug is below:]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [This prints two digits for exponent magnitude >=10, but uses %c for each digit. However, (-d)/10 and (-d)%10 are integers, so '0' + value gives correct char. BUT: for d=-10, prints "-10", which is correct. However, the real issue is in the positive two-digit case:]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [printf format string has only one %c, but two arguments provided. This is undefined behavior and will not print the second digit. Should be printf("%c%c", ...). This causes wrong output for exponents >=10.]
    }
    return 0;
}