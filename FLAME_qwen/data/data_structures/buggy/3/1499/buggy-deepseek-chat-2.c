#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not part of standard C11. Use fgets() instead.]
    puts(p1);
}