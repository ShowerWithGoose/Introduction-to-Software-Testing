#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int a = 0 , b , c ;
    char c1 = '+' , c2 , c3 ;
    while(c1 != '='){
        scanf("%d%c" , &b , &c2) ; @@ [The format "%d%c" does not skip whitespace, so if there's a space after the number, c2 will read the space instead of the operator, causing incorrect parsing and potentially infinite loop.]
        while('*'==c2 ||'/' == c2){
            scanf("%d%c" , &c , &c3) ; @@ [Same issue: "%d%c" reads space as c3, leading to wrong operator detection and possible infinite loop.]
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