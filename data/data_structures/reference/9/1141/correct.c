#include<stdio.h>
void front(int ,int );
void back(int ,int );
int x[100][2],y[100][2];
int n,len=1,markh=10000,markt=10000;
int main()
{
    scanf("%d",&n);
    int i=0,j,flag=1,temp,eve;
    for(i;i<n;i++)
    {
        scanf("%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
    }
    for(i=0;i<n&&i!=markh&&i!=markt;i++)
    {
        flag=len;
        len=1;
        markh=i;
        markt=i;
        front(x[i][0],y[i][0]);
        back(x[i][1],y[i][1]);
        if(len>flag)
        {
            temp=markh;
            eve=len;
        }
        
    }
    printf("%d %d %d",eve,x[temp][0],y[temp][0]);
    
}
void front(int x0,int y0)
{
      int i=0;
      for(i;i<n;i++)
      {
          if(x0==x[i][1]&&y0==y[i][1])
          {
              len++;
              markh=i;
              front(x[i][0],y[i][0]);
          }

      }
} 
void back(int x1,int y1)
{
      int i=0;
      for(i;i<n;i++)
      {
          if(x1==x[i][0]&&y1==y[i][0])
          {
              len++;
              markt=i;
              back(x[i][1],y[i][1]);
          }

      }
} 
