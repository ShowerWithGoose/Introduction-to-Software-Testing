#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

struct line{
int x1;
int y1;
int x2;
int y2;
}line[105];

int main()
{
    struct line temp;
    int n,m,z;
    int max=0,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(line[i].x1>line[j].x1){
                temp=line[j];
                line[j]=line[i];
                line[i]=temp;}
        }
    }
    for(int i=0;i<n;i++){
        z = i;
        m = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (line[z].x2==line[j].x1)
            {
                if (line[z].y2 == line[j].y1)
                {
                    m++;
                    z = j;
                }
            }
        }
        if (m > max)
        {
            max = m;
            x = line[i].x1;
            y = line[i].y1;
        }
    }
    printf("%d %d %d",max+1,x,y);

  return 0;
    }



