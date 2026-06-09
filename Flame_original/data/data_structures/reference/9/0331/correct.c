#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct line{
 int sx;int sy;
 int ex;int ey;
}a[120];
int main()
{
  int total;int maxline,maxi;int cnt=1;int r;int flag=1;
  maxline=0;maxi=0;
  scanf("%d",&total);
  for (int i = 0; i < total; i++)
  {
    scanf("%d",&a[i].sx);scanf("%d",&a[i].sy);
    scanf("%d",&a[i].ex);scanf("%d",&a[i].ey);
  }
  for (int i = 0; i < total; i++)
  {   
      r=i;
      for (int j = 0; j < total; j++)
      {
          if (j!=r)
            {
            if (a[r].ex==a[j].sx&&a[r].ey==a[j].sy)
            {
               
               //if ((a[r].ex-a[r].sx)*(a[j].ey-a[j].sy)!=(a[r].ey-a[r].sy)*(a[j].ex-a[j].sx))
               //{
                 cnt++;
               //}
               r=j;
               j=-1;
            }
          }
      }
      if (maxline<cnt)
      {
          maxline=cnt;
          maxi=i;
      }
      cnt=1;
  }
  printf("%d %d %d",maxline,a[maxi].sx,a[maxi].sy);
  return 0;

}
