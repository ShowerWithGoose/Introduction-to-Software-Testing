#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int a = 0 , b , c ;
    char c1 = '+' , c2 , c3 ;
    while(c1 != '='){
        scanf("%d%c" , &b , &c2) ; @@ [scanf format "%d%c" does not skip whitespace, so it may read space characters as operators instead of the actual operator or '='. This causes incorrect parsing of expressions with spaces.]
        while('*'==c2 ||'/' == c2){
            scanf("%d%c" , &c , &c3) ; @@ [Same issue: "%d%c" reads the next character immediately after the number, which could be a space, leading to wrong operator detection and premature termination or miscalculation.]
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