#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0};
char Stack[MAX+1];
int N;
void paixu(int m, int n)
{
    int i;

    if( n == 0){
        Stack[m] = '\0';
        puts(Stack); // @@ [The output format requires each integer to be separated by a space and printed on one line. Using puts() prints the string as-is without spaces between digits, and also appends a newline, but the digits themselves are not space-separated. Additionally, for N>9, '0'+i would produce non-digit characters, but since N<=10, i=10 causes '0'+10 which is ':', leading to incorrect output. However, the immediate error causing mismatch with expected output is missing space separation.]
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i; // @@ [When i is 10 (which is allowed since N can be up to 10), '0' + 10 equals 58, which is the ASCII code for ':', not "10". This causes incorrect character representation for numbers >=10. The program should handle multi-digit numbers, but it's storing only one char per number, which fails for N=10.]
            paixu(m+1,n-1);
            biaoji[i] = 0;
        }

}
int main ()
{
    scanf ("%d", &N);
    paixu(0,N);
    return 0;
}