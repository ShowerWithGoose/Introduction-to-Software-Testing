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
puts(pailie); // @@ [The output uses puts(), which prints the string followed by a newline, but the problem requires each integer in a permutation to be separated by a space. The current code stores digits as characters without spaces, so "12" is printed instead of "1 2".]
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i; // @@ [This stores the digit character (e.g., '1') directly into the array without adding a space after it. The output format requires space-separated integers, but the current implementation concatenates digits into a continuous string like "12".]
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}