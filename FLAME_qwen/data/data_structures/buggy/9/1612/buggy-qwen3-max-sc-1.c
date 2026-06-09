#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct 
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}line;
line lines[500];
int compare(const void*a,const void*b)
{
    line *c = a;
    line *d = b;
    return((*c).x1 - (*d).x1);//升序排序
}


int main()
{
    int n,i = 0,j = 0;
    int x,y,c;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].count = 1;
    }
    qsort(lines,n,sizeof(line),compare);

          for(i = n-1;i > 0;i--)//查找相连线段
        {
            for(j = i-1;j > 0;j--)
            {
                if((lines[j].x2 == lines[i].x1)&&(lines[j].y2 == lines[i].y1))
                {
                    lines[j].count += lines[i].count;
                    break;
                }
            }
        }
            
            x = lines[0].x1;
            y = lines[0].y1;
            c = lines[0].count;
            
        for(i = 1;i < n;i++)
        {
            if(lines[i].count > c)
            {
                x = lines[i].x1;
                y = lines[i].y1;
                c = lines[i].count;
            }
        }
        
        printf("%d %d %d",c,x,y);
        
        return 0;
    }