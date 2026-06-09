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
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, some compilers may not support it, leading to compilation errors.]
    int len = strlen(str);
    int l = 0, r = 0;
    while(str[r] != '.'){ // @@ [If input has no '.', this loop runs out of bounds causing undefined behavior or crash.]
        r++;
    }
    while(str[l] == '0' || str[l] == '.'){ // @@ [This skips all leading zeros and the decimal point, but if the number starts with non-zero digit, l remains 0 which is correct; however, if input is like "0.0...", this may skip everything incorrectly. Also, if string ends before finding non-zero, l may go out of bounds.]
        l++;
    }
    //r = strstr(str, '.') - str[0];
    printf("%c", str[l]); // @@ [If l >= len (e.g., input "0.0"), this accesses invalid memory.]
    if(str[l+1] != '\0'){ // @@ [Same issue: l+1 may be beyond string length.]
        printf(".");
        for(int i = l+1; str[i] != '\0'; i++){
            if(str[i] == '.') continue;
            printf("%c", str[i]);
        }
    }
    printf("e");
    int d = r - l >= 0 ? r - l - 1: r - l; // @@ [Logic for exponent calculation is flawed. For example, in "123.45", r=3, l=0 → d=2, which is correct (1.2345e2). But in "0.00123", r=1, l=3 → d = 1-3 = -2, but should be -3. Correct exponent is (position of first non-zero digit relative to decimal point).]
    if(d < 0 && d >= (-9)){
        printf("-%c", '0' - d); // @@ ['0' - d is wrong: if d=-3, '0' - (-3) = '0'+3 = '3', so prints "-3" as "-3", but format is "-%c", so outputs "-3" correctly? Wait: '0' - d when d negative → '0' + |d|, which is correct character. BUT: if d=-10, this branch not taken, goes to next. However, the real issue is exponent calculation above.]
    }
    else if(d >= 0 && d <= 9){
        printf("%c", '0' + d);
    }
    else if(d < (-9)){
        printf("-%c%c", '0' + (-d)/10, '0' + (-d)%10); // @@ [This prints two digits for exponent magnitude >=10, but format requires full integer (could be more than 2 digits). Also, (-d)%10 gives last digit, but for d=-123, this only prints "12", missing hundreds.]
    }
    else if(d >= 10){
        printf("%c", '0' + d/10, '0' + d%10); // @@ [printf with one %c but two arguments → undefined behavior. Should be printf("%c%c", ...). Also, same issue: only handles up to 2-digit exponents.]
    }
    return 0;
}