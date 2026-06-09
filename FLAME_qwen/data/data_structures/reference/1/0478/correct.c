#include <stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int flag[21];
char ceng[21];
int N;
void rank(int m,int n);
int main()
{
    scanf("%d",&N);
    rank(0,N);
    return 0;
}

void rank(int x,int y)
{
    int i,k;
    for(i=1;i<=N;i++)
    {
         if(y==0)//即后面没有数可以排了 
        {
            for(k=0;k<N;k++)
                printf("%c ",ceng[k]);
            printf("\n");
        return;
        }

        if(flag[i]==0)
        {
            flag[i]=1;
            ceng[x]=i+'0';
            rank(x+1,y-1);
            flag[i]=0;
        }

    }
}


