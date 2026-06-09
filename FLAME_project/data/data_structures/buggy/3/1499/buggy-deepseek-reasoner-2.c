#include <stdio.h>

int main(void){
    char p1[82]={0};
    char p2[82]={0};
    int move=0;
    gets(p1);
    puts(p1); // @@ This line outputs the input string directly without conversion to scientific notation, causing wrong answer for test case (e.g., input "0.9" outputs "0.9" instead of "9e-1").
}