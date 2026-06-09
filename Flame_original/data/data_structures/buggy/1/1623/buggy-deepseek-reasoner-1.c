#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0}; // @@ Array size is MAX (10), but indices 1..N up to 10 require size at least 11 to avoid out-of-bounds access.
char Stack[MAX+1];
int N;
void paixu(int m, int n)
{
    int i;

    if( n == 0){
        Stack[m] = '\0';
        puts(Stack); // @@ Output format error: puts prints the string without spaces between digits, but expected output requires each integer separated by a space (e.g., "1 2 3" instead of "123").
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i;
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