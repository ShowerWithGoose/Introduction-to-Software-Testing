#include<stdio.h>
int main()
{
    int a,b,i=0,n=0,n1,n2,j;
    char c;
    struct x
    {
        int xs;
        int zs

    };
    struct x xf,x1[100],x2[100],xc[100];
    while(scanf("%d %d",&a,&b)!=EOF)
    {
          x1[i].xs=a;
          x1[i].zs=b;
          i++;
          scanf("%c",&c);
          if(c=='\n') break;
    }
    n1=i;
    i=0;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
          x2[i].xs=a;
          x2[i].zs=b;
          i++;
          scanf("%c",&c);
          if(c=='\n') break;
    }
    n2=i;
    for(i=0;i<n1;i++)
    {
       for(j=0;j<n2;j++)
       {
           xc[n].xs=x1[i].xs*x2[j].xs;
           xc[n].zs=x1[i].zs+x2[j].zs;
           n++;
       }
    }
    for(i=0;i<n;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(xc[i].zs==xc[j].zs)
            {
                xc[i].zs=-1;
                xc[j].xs+=xc[i].xs;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1-i;j++)
        if(xc[j].zs>xc[j+1].zs)
        {
            xf=xc[j];
            xc[j]=xc[j+1];
            xc[j+1]=xf;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        if(xc[i].zs>=0)
            printf("%d %d ",xc[i].xs,xc[i].zs);
    }

}

