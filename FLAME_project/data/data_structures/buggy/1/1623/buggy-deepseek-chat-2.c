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
        puts(Stack);
        return;
    }
    for(i=1; i<=N; i++)
        if(biaoji[i] == 0 ){
            biaoji[i] = 1;
            Stack[m] = '0'+i;
            paixu(m+1,n-1); // @@ Error: Missing space between numbers. The reference program adds a space after each number by incrementing m by 2 (m+2) and placing a space at Stack[m+1]. This version only increments m by 1, so numbers are concatenated without spaces, e.g., "12" instead of "1 2".
            biaoji[i] = 0;
        }

}
int main ()
{
    scanf ("%d", &N);
    paixu(0,N);
    return 0;
}