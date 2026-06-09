#include <stdio.h>
#define MAX 10
char mark[MAX]={0}; // @@ Array size is MAX (10) but indices 1..N with N up to 10 cause out-of-bounds access for i=10.
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
puts(pailie); // @@ Output missing spaces between numbers; should print each character followed by a space.
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i; // @@ For i=10, '0'+i is not a digit; each number should be handled as integer, not a single character.
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}