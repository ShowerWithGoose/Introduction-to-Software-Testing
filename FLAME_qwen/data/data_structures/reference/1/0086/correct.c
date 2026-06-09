#include <stdio.h>
#include <stdlib.h>
int c;
char p[20];
int mark[20]={0};
void pai(int m,int w)
{
    if(m==0)
    {
        int k;
        for(k=0;p[k]!='\0';k++)
            printf("%c ",p[k]);
        printf("\n");
        return;
    }
    else{
            int i;
            for(i=0;i<=c-1;i++)
            {
                if(mark[i]==0)
                {
                    mark[i]=1;
                    p[w]=i+'0'+1;
                    pai(m-1,w+1);
                    mark[i]=0;
                }
            }

    }
}

int main()
{
    int a;
    scanf("%d",&a);
    p[a-1]='\0';
    c=a;
    pai(a,0);
    return 0;
}



