#include <stdio.h>
struct line
{
    int qd[2],zd[2];
}p[200],temp;
int main()
{
    int n;
    scanf("%d",&n);
    int i,cs=1,*zz1=NULL,*zz2=NULL,cs1=0,hzb=0,zzb=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&p[i].qd[0],&p[i].qd[1],&p[i].zd[0],&p[i].zd[1]);
    }
    int j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].qd[0]>p[j].qd[0])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {   cs=1;
        zz1=&p[i].zd[0];
        zz2=&p[i].zd[1];
        for(j=i+1;j<n;j++)
        {
            if(*zz1==p[j].qd[0]&&*zz2==p[j].qd[1])
            {
                cs++;
                zz1=&p[j].zd[0];
                zz2=&p[j].zd[1];
            }
        }
        if(cs>cs1)
        {
            cs1=cs;
            hzb=p[i].qd[0];
            zzb=p[i].qd[1];
        }
    }
    printf("%d %d %d\n",cs1,hzb,zzb);
    return 0;
}



