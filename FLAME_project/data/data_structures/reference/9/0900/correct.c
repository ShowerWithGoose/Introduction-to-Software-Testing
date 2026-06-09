#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct L {
    int x1;
    int y1;
    int x2;
    int y2;
};
    struct L in[150];
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d %d %d %d", &in[i].x1, &in[i].y1, &in[i].x2, &in[i].y2);
    struct L tmp;
    for(i=0; i<n; i++)
    for(j=i; j<n; j++){
        if(in[i].x1 > in[j].x1)
        {
            tmp = in[i];
            in[i] = in[j];
            in[j] = tmp;
        }
    }
    
    int count_max=1,x1_max = 0,y1_max = 0;
    for(i=0; i<n; i++)
    {
        int x2,y2,count=1;
        x2=in[i].x2;
        y2=in[i].y2;
        for(j=i+1; j<n; j++)
        {
            if( x2==in[j].x1 && y2==in[j].y1 )
            {
                count++;
                x2=in[j].x2;
                y2=in[j].y2;
            }
        }
        if(count > count_max)
        {
            count_max=count;
            x1_max=in[i].x1;
            y1_max=in[i].y1;
        }
    }
    
    printf("%d %d %d\n", count_max, x1_max,y1_max);
    return 0;
}

