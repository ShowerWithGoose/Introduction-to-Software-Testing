#include<stdio.h>
int n, a=0, m, num[12]={0};
char line[12];
void cycle(int n, int a)
{
    if(n==0)
    {
            for(int i=0; line[i]!='\0'; i++)
        {
            int z;
            z=line[i]-'0';
            printf("%d",z);
            if(i!=a-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    for(int j=1; j<=a; j++)
    {
        if(num[j]==0)
        {
            num[j]=1;
            line[a-n]=j+'0';
            cycle(n-1, a);
            num[j]=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    a=n;
    cycle(n,a);
    return 0;
}



