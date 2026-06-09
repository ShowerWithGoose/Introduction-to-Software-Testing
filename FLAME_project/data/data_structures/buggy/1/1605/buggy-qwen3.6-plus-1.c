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
puts(pailie); // @@ The output format is incorrect. puts prints the string followed by a newline, but the integers are stored as characters without spaces. For N=2, it prints "12" instead of "1 2 ". The reference program uses a loop to print each character followed by a space.
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