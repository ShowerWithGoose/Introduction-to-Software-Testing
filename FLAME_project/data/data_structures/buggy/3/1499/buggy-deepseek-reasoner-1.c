#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ This line outputs the input unchanged instead of converting to scientific notation as required. The program lacks the necessary parsing and formatting logic to produce the expected output "9e-1".
}