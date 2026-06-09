#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow. Also, the program does not implement the required decimal-to-scientific-notation conversion.]
    puts(p1); // @@ [This only prints the input back; it does not produce the scientific notation output as required by the problem.]
}