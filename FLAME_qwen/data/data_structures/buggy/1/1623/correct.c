#include <stdio.h>
#define MAX 10
int biaoji[MAX] = {0};
char s[MAX+1];
int N;
void paixu(int m, int n)
{
	int i;
	if( n == 0){
		s[m] = '\0';
		for(int i=0;i<strlen(s);i++)
        {
            printf("%c ",s[i]);
        }
        printf("\n");
		return;
	}
	for(i=1; i<=N; i++)
		if(biaoji[i] == 0 ){
			biaoji[i] = 1;
			s[m] = '0'+i;
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





