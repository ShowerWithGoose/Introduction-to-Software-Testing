#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0}; // @@ Array size is 10, but N can be up to 10, causing out-of-bounds access when i=10. Should be MAX+1 or 11.
char Stack[MAX+1];
int N;
void paixu(int m, int n)
{
    int i;

    if( n == 0){
        Stack[m] = '\0';
        puts(Stack); // @@ Output format requires spaces between integers, but puts prints the string without spaces. Should iterate and print each character followed by a space.
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