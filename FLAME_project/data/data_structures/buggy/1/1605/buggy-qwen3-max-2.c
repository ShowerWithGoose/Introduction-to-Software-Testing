#include <stdio.h>
#define MAX 10
char mark[MAX]={0}; // @@ [Array size is too small; should be at least MAX+1 (11) to index up to N=10]
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
puts(pailie); // @@ [Uses puts() which prints characters without spaces between digits, and adds a newline; expected output requires space-separated integers]
return ;
}
    for(i=1;i<=N;i++)
    {
        if(mark[i]==0) {
            mark[i]=1;
            pailie[m]='0'+i; // @@ [Stores ASCII character instead of integer; when printed via puts(), outputs concatenated digits like "12" instead of "1 2"]
        
        rank(m+1,n-1);
        mark[i]=0;
    }
}
}