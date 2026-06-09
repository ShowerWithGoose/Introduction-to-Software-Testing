#include <stdio.h>
#define MAX 10
char mark[MAX]={0};
char pailie[MAX+1];
int N;
void rank(int m, int n);
int main()
{
scanf("%d",&N);
rank(0,N);
return 0;
}
void rank(int m,int n){int i;
if(n==0)
{pailie[m]='\0';
puts(pailie); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and then a newline. The current code stores characters like '1', '2', etc., so puts() prints them without spaces between digits, leading to incorrect output format. Additionally, for N>9, this approach fails, but since N<=10, '10' cannot be represented as a single char, causing logical error for N=10. However, the immediate format error is due to missing spaces between numbers.]
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i; // @@ [This only works for i from 1 to 9. When N=10, i=10 leads to '0'+10 which is ':', not "10". Thus, it cannot represent two-digit numbers, violating the problem requirement for N up to 10. This causes incorrect output for N=10 and is a logical error in data representation.]
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}