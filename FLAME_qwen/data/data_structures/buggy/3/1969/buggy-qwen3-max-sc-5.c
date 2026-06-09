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
    gets(str); // @@ [Use of unsafe function 'gets' which has been removed from C11 standard and may cause buffer overflow; also, the test environment may not support it leading to runtime or compilation issues depending on compiler flags.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){ // @@ [If input has no decimal point, this loop runs past the end of string causing undefined behavior.]
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This skips all leading zeros and the decimal point, but if the number starts with non-zero digit before '.', 'l' may incorrectly skip valid digits or go out of bounds. Also, if the number is like "0.123", this sets l to first non-zero after decimal, which is correct, but logic is fragile.]
        l++;
    }
    //r = strstr(str, '.') - str[0];
    printf("%c", str[l]); // @@ [If l >= len (e.g., input "0.0" though problem says no trailing zeros, but still), this accesses invalid memory.]
    if(str[l+1] != '\0'){ // @@ [Assumes l+1 is within bounds; may read beyond string if l points to last character.]
        printf(".");
        for(int i = l+1; str[i] != '\0'; i++){
            if(str[i] == '.') continue;
            printf("%c", str[i]);
        }
    }
    printf("e");
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [Incorrect exponent calculation. For example, "123.45": r=3, l=0 → d=2, correct. But for "0.00123": r=1, l=3 → d = 1-3 = -2, but should be -3. Formula is wrong for numbers < 1.]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ [Should be '0' + (-d), not '0' - d. E.g., d=-3 → '0' - (-3) = '0'+3 = '3', but written as "-3", so this prints "-3" correctly? Wait: '0' - d when d=-3 → '0' - (-3) = '0'+3 = '3', so printf("-%c", '3') → "-3", which is correct. But expression is confusing; however, actual bug is below.]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [For d=-12: (-d)=12 → prints "-12", correct. But what if d=-10? (-d)%10=0 → '0', so "-10", correct. However, this assumes two-digit negative exponents only. What about three digits? Problem doesn't specify input size, but buffer is 105, so exponent could be large. But more critically, the exponent calculation itself is flawed.]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [printf with two arguments but only one %c format specifier → undefined behavior. Should be printf("%c%c", ...). This is a critical format string error.]
    }
    return 0;
}