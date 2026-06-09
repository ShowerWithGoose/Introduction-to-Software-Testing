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
puts(pailie); // @@ The output format is incorrect. The problem requires each integer to be separated by a space, but puts() outputs the string without spaces between digits, e.g., "123" instead of "1 2 3".
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