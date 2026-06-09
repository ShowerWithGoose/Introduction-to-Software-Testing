#include <stdio.h>
#define MAX 10
char mark[MAX]={0}; // @@ Array size is 10, but indices up to N (max 10) are used, so mark[10] is out of bounds. Should be char mark[MAX+1] or int mark[11].
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
puts(pailie); // @@ prints the permutation as a continuous string without spaces. Required output format has spaces between numbers.
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