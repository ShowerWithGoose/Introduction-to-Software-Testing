#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0}; // @@ Unused variable; not needed for the conversion.
    int move=0; // @@ Unused variable; not needed for the conversion.
    gets(p1); // @@ Uses gets() which is unsafe and deprecated; also does not parse the decimal number for scientific notation.
    puts(p1); // @@ Outputs the raw input instead of the required scientific notation format (e.g., "2.34e5").
}