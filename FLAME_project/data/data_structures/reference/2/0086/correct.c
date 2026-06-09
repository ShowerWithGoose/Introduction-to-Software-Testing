#include <stdio.h>
#include <stdlib.h>

int main()
{
    char biao[100];
    int b[100];
    int e,i;
    for(i=0;;i+=2)
    {
        scanf("%d %c",&b[i],&biao[i+1]);
        if(biao[i+1]=='=')
            break;
    }
    for(i=1;biao[i]!='=';i+=2)
    {
        if(biao[i]=='*'||biao[i]=='/')
        {
            int j;
            for(j=i-1;biao[i]=='*'||biao[i]=='/';i+=2)
            {
                if(biao[i]=='*')b[j]*=b[i+1];
                if(biao[i]=='/')b[j]/=b[i+1];
            }
            i-=2;
        }
    }
    int j;
    for(i=1;biao[i]!='=';i+=2)
    {
        if(biao[i]=='+')
            b[0]+=b[i+1];
        if(biao[i]=='-')
            b[0]-=b[i+1];
    }
    printf("%d",b[0]);
    return 0;
}




