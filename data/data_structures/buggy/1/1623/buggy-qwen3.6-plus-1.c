#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0}; // @@ Array size is 10, but indices 1 to N are accessed. When N=10, biaoji[10] causes out-of-bounds access. Should be MAX+1.
char Stack[MAX+1];
int N;
void paixu(int m, int n)
{
    int i;

    if( n == 0){
        Stack[m] = '\0';
        puts(Stack); // @@ Does not output spaces between numbers as required by the problem, and cannot handle multi-digit numbers like 10.
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i; // @@ Converts integer to a single ASCII character, which fails for i=10 and prevents correct space-separated formatting.
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