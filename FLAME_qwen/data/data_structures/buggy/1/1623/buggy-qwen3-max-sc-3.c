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
        puts(Stack); // @@ [The output format requires space-separated integers followed by a newline, but puts() outputs the string as-is without spaces between digits and adds an extra newline. Also, storing numbers as characters like '1', '2' etc. results in concatenated digits (e.g., "12" instead of "1 2").]
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i; // @@ [Storing integer i as a character in a char array leads to incorrect output formatting. The problem requires space-separated integers, not a string of digits. This approach cannot produce spaces between numbers.]
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