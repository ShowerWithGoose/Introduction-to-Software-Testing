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
puts(pailie); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space. The current code stores characters like '1', '2', etc., and prints them as a string without spaces between digits, which fails for N >= 10 or even misformats single-digit numbers because no spaces are inserted between them. Additionally, for N=10, '0'+10 is not a valid single character representation.]
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i; // @@ [This only works correctly for i from 1 to 9. When N=10, '0'+10 equals ':', which is incorrect. Moreover, the program stores characters instead of handling multi-digit numbers, but since N<=10, only 10 causes an issue. However, the bigger issue is that the output format requires space-separated integers, not concatenated characters.]
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}