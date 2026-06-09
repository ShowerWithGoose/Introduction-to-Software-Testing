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
        puts(Stack); // @@ [Using puts() prints the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and the entire permutation on one line. The current implementation stores digits as characters (e.g., '1', '2') and prints them without spaces between them, which violates the output format. Additionally, puts() adds a newline, but the lack of spaces makes the output incorrect.]
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