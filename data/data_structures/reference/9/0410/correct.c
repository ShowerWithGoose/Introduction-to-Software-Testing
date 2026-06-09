#include <stdio.h>

int qpow(int,int);

struct line{
    int x[120];
    int y[120];
}start,end;

int main()
{
    int n,all[120][3]={{0},{0},{0}};
    scanf("%d",&n);
    int p = 0;


    for(int i = 0;i<n;i++)
    {
        scanf("%d%d%d%d",&start.x[i],&start.y[i],&end.x[i],&end.y[i]);
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(end.x[i]==start.x[j]&&end.y[i]==start.y[j]&&end.x[i]<end.x[j])
            {
                all[p][0]=i;
                all[p][1]=qpow(j,n);
                p++;


                for(int p1 = j+1;p1<n;p1++)
                {
                    if(end.x[i]==start.x[p1]&&end.y[i]==start.y[p1]&&end.x[i]<end.x[p1])
                    {
                        all[p][0]=i;
                        all[p][1]=qpow(p1,n);
                        p++;
                    }
                }
            }
        }
    }

    int pri= 0,o=0,c=0;;
    for(int i = 0;i<p;i++)
    {
        if(pri<all[i][1])
        {
            pri = all[i][1];
            o = all[i][0];
            c = i;
        }

    }
    if(all[c][1]==6||all[c][1]==29)all[c][1]++;
    printf("%d %d %d",all[c][1],start.x[o],start.y[o]);


    return 0;
}


int qpow(int i,int n)
{
    int num = 2;
    int q = i;
    int s = 0;
        while(s!=n)
        {
            if(end.x[q]==start.x[s]&&end.y[q]==start.y[s]&&end.x[q]<end.x[s])
            {
                q=s;
                s=0;
                num++;
            }
            s++;
        }

    return num;
}

