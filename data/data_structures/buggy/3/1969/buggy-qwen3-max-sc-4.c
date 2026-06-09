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
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, some compilers/environments may not support it, leading to compilation errors or runtime issues.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){ // @@ [If input has no decimal point, this loop runs out of bounds, causing undefined behavior. Problem states input always has digits before and after decimal, but code doesn't validate presence of '.', risking infinite loop or segfault.]
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This skips all leading zeros and the decimal point, but if the number starts with '0.' (like "0.123"), l becomes index of first non-zero after decimal. However, if input is like "0.0", this may go out of bounds. Also, condition should not skip '.' when looking for first significant digit.]
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
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [Logic for exponent calculation is flawed. For example, in "123.45", r=3, l=0 → d=2, correct. But in "0.00123", r=1, l=3 → d = 1-3 = -2, but actual exponent should be -3. The formula doesn't correctly compute position relative to first significant digit.]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ [Incorrect character conversion: '0' - d when d is negative gives wrong digit. Example: d = -3 → '0' - (-3) = '0'+3 = '3', so prints "-3" as "-3", which seems okay, but expression is misleading. However, more critically, if d=-10, this branch isn't taken, but next branch handles two-digit negatives. BUT: '0' - d is same as '0' + |d|, so actually works for single-digit. Still, style issue, not main bug.]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [This prints two-digit negative exponents, but format is wrong: e.g., d=-12 → prints "-12", which is correct. However, the earlier logic for d is wrong, so even if printing is right, exponent value is incorrect.]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [printf with one %c but two arguments — this is a critical error. It only prints the first digit (tens place), ignoring the units digit. Should be printf("%c%c", ...). This causes wrong output for exponents >=10.]
    }
    return 0;
}