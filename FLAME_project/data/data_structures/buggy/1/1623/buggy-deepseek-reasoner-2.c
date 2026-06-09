#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0}; // @@ [Array size too small; should be MAX+1 to accommodate index N up to 10]
char Stack[MAX+1]; // @@ [Stack size insufficient; need at least 2*MAX to include spaces between digits]
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
            Stack[m] = '0'+i; // @@ [Missing space insertion after digit; should also set Stack[m+1]=' ']
            paixu(m+1,n-1); // @@ [Incorrect index; should be m+2 to account for the space character]
            biaoji[i] = 0;
        }

}
int main ()
{
    scanf ("%d", &N);
    paixu(0,N);
    return 0;
}