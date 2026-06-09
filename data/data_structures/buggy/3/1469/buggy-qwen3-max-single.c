#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a[100];
    scanf("%s", a);
    int x = -1, y = -1;
    int flag = 1;
    int len = strlen(a);
    for(int i = 0; i < len&&(y == -1 || x == -1); i++){
        if(a[i]=='.'){
            x = i;
        }
        if(a[i]!= '0' && a[i] != '.'){
            y = i;
            flag = 0;
        }
    }
    printf("%c", a[y]); // @@ [If the input is "0.0...", y remains -1, leading to undefined behavior accessing a[-1]]
    
    if(y != len-1){
        printf(".");
    }
    
    for(int i = y+1; i < len; i++){
        if(a[i]=='.'){
            printf("%c", a[i]); // @@ [This prints '.' in the mantissa, which violates scientific notation format]
        }
    }
    
    if(x > y){
        y++;
    }
    
    printf("e%d\n", x-y); // @@ [Exponent calculation is incorrect for numbers < 1 and doesn't handle cases where decimal point is absent]
    return 0;
}