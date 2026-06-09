#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char z;
    int a[100][2],na;
    int b[100][2],nb;

    for(na=0;na<100;na++)
    {
        scanf("%d%d%c",&a[na][0],&a[na][1],&z);
        if(z=='\n')
        {
            break;
        }
    }
    for(nb=0;nb<100;nb++)
    {
        scanf("%d%d%c",&b[nb][0],&b[nb][1],&z);
        if(z=='\n'||b[nb][1]==0)
        {
            break;
        }
    }
    
    int o,p,tmp,ot=0;
    int out[100][2]={0};
    
    for(int i=0;i<=na;i++)
    {
        for(int j=0;j<=nb;j++)
        {
            tmp=1;
            o=a[i][0]*b[j][0];
            p=a[i][1]+b[j][1];
            for(int k=0;k<ot;k++)
            {
                if(p==out[k][1])
                {
                    out[k][0]+=o;
                    tmp=0;
                    break;
                }
            }
            if(tmp==1&&o!=0)
            {
                out[ot][0]=o;
                out[ot][1]=p;
                ot++;
            }
        }
    }
    int temp;
    for(int i=0;i<ot;i++)
    for(int j=0;j<ot;j++)
    {
        if(out[j][1]<out[j+1][1])
        {
            temp=out[j][1];
            out[j][1]=out[j+1][1];
            out[j+1][1]=temp;
            temp=out[j][0];
            out[j][0]=out[j+1][0];
            out[j+1][0]=temp;
        }
    }

    for(int i=0;i<ot;i++)
    {
        printf("%d %d ",out[i][0],out[i][1]);
    }
    
    return 0;
}

