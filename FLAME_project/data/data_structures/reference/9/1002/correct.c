#include <stdio.h>
int hot;
int find(int a,int b,int m[],int n[],int p[],int q[],int h,int N)
{
    int i;
    for(i=0;i<N;i++)
        if(i!=h)
        {
            if(a==m[i]&&b==n[i])
                find(p[i],q[i],m,n,p,q,i,N),hot++;
            if(a==p[i]&&b==q[i])
                find(m[i],n[i],m,n,p,q,i,N),hot++;
        }
    return hot+1;
}

int main() {
    int x2[100];
    int y2[100];
    int x1[100];
    int y1[100];
    int N;
    int sum[100][2]={};
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d",&x1[i]);
        scanf("%d",&y1[i]);
        scanf("%d",&x2[i]);
        scanf("%d",&y2[i]);

    }

    for(i=0;i<N;i++)
    {
        hot=0;
        sum[i][0]=find(x1[i],y1[i],x1,y1,x2,y2,i,N);
        hot=0;
        sum[i][1]=find(x2[i],y2[i],x1,y1,x2,y2,i,N);
    }
    int max,numb=0;
    max=sum[0][1];
    for(i=1;i<N;i++)
    {
        if(sum[i][1]>max) max=sum[i][1],numb=i;
    }
    int flag=0;
    for(i=0;i<N;i++)
        if(sum[i][0]==max&&x2[i]<x1[numb]) numb=i,flag=1;
   if(flag==0) printf("%d %d %d",max,x1[numb],y1[numb]);
   else  printf("%d %d %d",max,x2[numb],y2[numb]);
   return 0;
}

