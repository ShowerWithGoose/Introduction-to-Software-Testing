#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
}Line;

struct 
{
    int x;
    int y;
    int length;
}Max;

int main()
{   
    int n;
    Line table[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&table[i].x1,&table[i].y1,&table[i].x2,&table[i].y2);
        table[i].flag=0;
    }
    Max.length=1;
    for(int i=0;i<n;i++)
    {
        if(table[i].flag!=1)
        {
            int lng=1,lng_=0;
            table[i].flag=1;
            while(lng_!=lng)
            {
                lng_=lng;
                for(int j=i+1;j<n;j++)
                {
                    if(table[j].flag!=1)
                    {
                        if(table[i].x1==table[j].x2&&table[i].y1==table[j].y2)
                        {
                            table[i].x1=table[j].x1;
                            table[i].y1=table[j].y1;
                            table[j].flag=1;
                            lng++;
                        }
                        else if(table[i].x2==table[j].x1&&table[i].y2==table[j].y1)
                        {
                            table[i].x2=table[j].x2;
                            table[i].y2=table[j].y2;
                            table[j].flag=1;
                            lng++;
                        }
                    }
                }
            }
            
            if(lng>Max.length)
            {
                Max.x=table[i].x1;
                Max.y=table[i].y1;
                Max.length=lng;
            }
        }
    }
    printf("%d %d %d",Max.length,Max.x,Max.y);
    return 0; 
}
