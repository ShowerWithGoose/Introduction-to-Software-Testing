#include<stdio.h>
struct coordinate{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
}co[105],para;
int main()
{
    int i,j,num,x,y,max,b,length,k;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        scanf("%d%d%d%d",&co[i].x1,&co[i].y1,&co[i].x2,&co[i].y2);
    }
    for(i=1;i<=num;i++)
    for(j=1;j<num;j++)
    {
        if(co[j].x1>=co[j+1].x1)
        {
            para=co[j];
            co[j]=co[j+1];
            co[j+1]=para;
        }
    }
    for(i=1;i<=num;i++)
    {
        if(co[i].time==0)
        {
        	co[i].time=1;
            x=co[i].x2;
            y=co[i].y2;
            length=1;
            while(1)
            {
                b=0;
                for(j=1;j<=num;j++)
                {
                    if(x==co[j].x1&&y==co[j].y1)
                    {
                        b=1;
                        length++;
                        x=co[j].x2;
                        y=co[j].y2;
                        co[j].time=1;
                        break;
                    }
                }
                if(b==0) break;
            }
            if(length>max)
            {
                max=length;
                k=i;
            }
        }
    }
    printf("%d %d %d",max,co[k].x1,co[k].y1);
}

