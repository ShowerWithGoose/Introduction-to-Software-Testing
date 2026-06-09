

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int xa;
    int ya;
    int xb;
    int yb;
    int num;
};
struct node line[100];

int main()
{
    int n, p=0,i, j, flag, max=0, m=0;   
    int x1, x2, y1, y2;
    scanf("%d",&n);
    while(n--)
    {
        flag = 0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(i=0;i<p;i++)    
        {
            if(x1==line[i].xb && y1==line[i].yb)  
            {
                line[i].xb = x2;
                line[i].yb = y2;
                line[i].num++;
                flag = 1;
                break;
            }
            if(x2==line[i].xa && y2==line[i].ya)  
            {
                line[i].xa = x1;
                line[i].ya = y1;
                line[i].num++;
                flag = 1;
                break;
            }
        }
        if (flag==0)    
        {
            line[p].xa = x1;
            line[p].ya = y1;
            line[p].xb = x2;
            line[p].yb = y2;
            line[p].num = 1;
            p++;
        }
    }
    for(i=0;i<p;i++)    
    {
    	j=i;
        while(j<p)
        {
            if(line[j].xb==line[i].xa && line[j].yb==line[i].ya)  
            {
                line[i].xa = line[j].xa;
                line[i].ya = line[j].ya;
                line[i].num = line[i].num+line[j].num;
                i--;
                break;
            }
            if(line[j].xa==line[i].xb && line[j].ya==line[i].yb)  
            {
                line[i].xb = line[j].xb;
                line[i].yb = line[j].yb;
                line[i].num = line[i].num+line[j].num;
                i--;
                break;
            }
            j++;
        }
    }
    i=0;
    while(i<p)
    {
        if(line[i].num > max)
        {
            m = i;
            max = line[i].num;
        }
        i++;
    }
    printf("%d %d %d",line[m].num,line[m].xa,line[m].ya);
    return 0;
}

