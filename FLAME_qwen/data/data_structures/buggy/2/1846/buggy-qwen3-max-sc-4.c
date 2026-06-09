#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int a = 0 , b , c ;
    char c1 = '+' , c2 , c3 ;
    while(c1 != '='){
        scanf("%d%c" , &b , &c2) ; @@ [Missing space in format string causes incorrect parsing of operator following number due to whitespace handling; should be "%d %c" to skip whitespace]
        while('*'==c2 ||'/' == c2){
            scanf("%d%c" , &c , &c3) ; @@ [Same issue: missing space in format string "%d%c" may read newline or space as operator instead of skipping whitespace]
            if('*' ==c2)
                b *= c ;
            else if('/' ==c2)
                b /= c ;
            c2 = c3 ;
        }
        if('+' == c1)
            a += b ;
        else if('-' == c1)
            a -= b ;
        c1 = c2 ;
    }
    printf("%d" , a) ;
    return 0;
}