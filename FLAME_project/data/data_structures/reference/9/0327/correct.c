#include <stdio.h>
#include <stdlib.h>
struct line
{
    int n;
    int in1,in2;
    int out1,out2;
};
int main()
{
    int a,x1,y1,x2,y2,flag,cnt=0,max=0,cntmax;
    struct line l[100];
    for(int i=0;i<100;i++)
    {
        l[i].n=1;
        l[i].in1=-1;
        l[i].in2=-1;
        l[i].out1=-1;
        l[i].out2=-1;
    }
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        flag=0;
        scanf("%d %d %d %d ",&x1,&y1,&x2,&y2);
        for(int j=0;j<=cnt;j++)
        {
            if(l[j].in1==x1&&l[j].in2==y1&&flag==0)
            {
                l[j].in1=x2;
                l[j].in2=y2;
                l[j].n++;
                flag=1;
            }
            if(l[j].out1==x1&&l[j].out2==y1&flag==0)
            {
                l[j].out1=x2;
                l[j].out2=y2;
                l[j].n++;
                flag=1;
            }
            if(l[j].in1==x2&&l[j].in2==y2&&flag==0)
            {
                l[j].in1=x1;
                l[j].in2=y1;
                l[j].n++;
                flag=1;
            }
            if(l[j].out1==x2&&l[j].out2==y2&&flag==0)
            {
                l[j].out1=x1;
                l[j].out2=y1;
                l[j].n++;
                flag=1;
            }
        }
        if(flag==0)
        {
            l[cnt].in1=x1;
            l[cnt].in2=y1;
            l[cnt].out1=x2;
            l[cnt].out2=y2;
            cnt++;
        }
    }
    
    for(int i=0;i<cnt;i++)
    {
        if(l[i].n>max)
        {
            max=l[i].n;
            cntmax=i;
        }
    }
    flag=1;
    while(flag==1)
    {
        flag=0;
    for(int j=0;j<cnt;j++)
    {
        if(j==cntmax)
        continue;
        if(l[j].in1==l[cntmax].in1&&l[j].in2==l[cntmax].in2)
        {
            l[cntmax].in1=l[j].out1;
            l[cntmax].in2=l[j].out2;
            l[cntmax].n+=l[j].n;
            l[j].n=0;
            l[j].in1=-1;
            l[j].in2=-1;
            l[j].out1=-1;
            l[j].out2=-1;
            flag=1;
        }
        if(l[j].out1==l[cntmax].in1&&l[j].out2==l[cntmax].in2)
        {
            l[cntmax].in1=l[j].in1;
            l[cntmax].in2=l[j].in2;
            l[cntmax].n+=l[j].n;
            l[j].n=0;
            l[j].in1=-1;
            l[j].in2=-1;
            l[j].out1=-1;
            l[j].out2=-1;
            flag=1;
        }
        if(l[j].in1==l[cntmax].out1&&l[j].in2==l[cntmax].out2)
        {
            l[cntmax].out1=l[j].out1;
            l[cntmax].out2=l[j].out2;
            l[cntmax].n+=l[j].n;
            l[j].n=0;
            l[j].in1=-1;
            l[j].in2=-1;
            l[j].out1=-1;
            l[j].out2=-1;
            flag=1;
        }
        if(l[j].out1==l[cntmax].out1&&l[j].out2==l[cntmax].out2)
        {
            l[cntmax].out1=l[j].in1;
            l[cntmax].out2=l[j].in2;
            l[cntmax].n+=l[j].n;
            l[j].n=0;
            l[j].in1=-1;
            l[j].in2=-1;
            l[j].out1=-1;
            l[j].out2=-1;
            flag=1;
        }
    }
    }
    if(l[cntmax].in1<l[cntmax].out1)
    printf("%d %d %d\n",l[cntmax].n,l[cntmax].in1,l[cntmax].in2);
    if(l[cntmax].in1>=l[cntmax].out1)
    printf("%d %d %d\n",l[cntmax].n,l[cntmax].out1,l[cntmax].out2);
    return 0;
}
