#include <stdio.h>
#define MAX 10 // @@ Insufficient for array indexing when N=10 (biaoji[10] out-of-bounds) and insufficient for Stack size when spaces are inserted.
int biaoji[MAX] = {0}; // @@ Array size too small; should be MAX+1 to accommodate index up to N.
char Stack[MAX+1]; // @@ Stack size insufficient for storing spaces between digits; should be 2*MAX+1.
int N;
void paixu(int m, int n)
{
    int i;

    if( n == 0){
        Stack[m] = '\0';
        puts(Stack);
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i; // @@ Missing assignment Stack[m+1] = ' '; to insert space between numbers.
            paixu(m+1,n-1); // @@ Should be paixu(m+2,n-1); because space consumes one extra index.
            biaoji[i] = 0;
        }

}
int main ()
{
    scanf ("%d", &N);
    paixu(0,N);
    return 0;
}