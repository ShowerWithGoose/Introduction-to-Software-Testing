#include <stdio.h>
#define MAX 10
char mark[MAX]={0}; // @@ Array size should be at least 11 (MAX+1) to safely access mark[10] when N=10, otherwise it causes out-of-bounds access.
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
puts(pailie); // @@ Output format requires integers separated by spaces, but puts prints the concatenated string without spaces. Should iterate and print each number with a space.
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