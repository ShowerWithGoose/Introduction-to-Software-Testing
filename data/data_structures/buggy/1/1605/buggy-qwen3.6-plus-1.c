#include <stdio.h>
#define MAX 10
char mark[MAX]={0}; // @@ Array size is 10, but indices up to 10 are accessed when N=10, causing out-of-bounds access. Size should be at least 11.
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
puts(pailie); // @@ Outputs the permutation without spaces between numbers, violating the output format requirement. Should print each character followed by a space.
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i;
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}