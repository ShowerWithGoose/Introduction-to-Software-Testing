#include <stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int a = 0 , b , c ;
    char c1 = '+' , c2 , c3 ;
    while(c1 != '='){
        scanf("%d%c" , &b , &c2) ; // @@ The format string "%d%c" does not skip whitespace before reading the character. If there are spaces in the input (e.g., "10 +"), c2 will read a space instead of the operator '+'. This causes the inner while loop to be skipped incorrectly, and c2 (space) is assigned to c1. In the next iteration, scanf tries to read an integer but encounters the operator or space, leading to parsing errors or infinite loops if the input buffer isn't consumed correctly, resulting in Time Limit Exceeded or Wrong Answer. It should be " %d %c" or similar to handle spaces.
        while('*'==c2 ||'/' == c2){
            scanf("%d%c" , &c , &c3) ; // @@ Similarly, this scanf does not skip whitespace before reading the character c3. If there are spaces after the number c, c3 might read a space instead of the next operator, breaking the logic for subsequent high-precedence operations.
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