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
            Stack[m] = '0'+i; // @@ The output format requires spaces between numbers (e.g., "1 2"), but this line only stores the digit. A space needs to be added after the digit or handled during output. Additionally, the buffer size might be insufficient if spaces are included without adjusting the logic or buffer size properly, but primarily the missing space causes the Wrong Answer.
            paixu(m+1,n-1); // @@ Because the space is missing in the previous step, the index increment is also likely incorrect for the desired format "1 2 ". If we add a space after each number, the next position should be m+2. However, simply changing this line without fixing the storage logic is incomplete. The core error is the lack of space separation in the stored string.
            biaoji[i] = 0;
        }

}
int main ()
{
    scanf ("%d", &N);
    paixu(0,N);
    return 0;
}