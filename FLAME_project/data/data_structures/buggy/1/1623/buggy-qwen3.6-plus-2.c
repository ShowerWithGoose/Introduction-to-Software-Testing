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
            Stack[m] = '0'+i; // @@ The output format requires spaces between numbers (e.g., "1 2"), but this code only stores the digit character without adding a space separator, resulting in concatenated digits like "12". Additionally, the buffer size and logic do not account for the extra space characters needed for correct formatting.
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