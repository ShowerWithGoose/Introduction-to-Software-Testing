#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int z,x,c;
struct xy
{
    int x1;
    int y1;
    int x2;
    int y2;
};
void left(struct xy s[],int n,int N)//起始删除点；坐标个数
{
    for(int i=n;i<N;i++)
    {
        s[i].x1=s[i+1].x1;
        s[i].y1=s[i+1].y1;
        s[i].x2=s[i+1].x2;
        s[i].y2=s[i+1].y2;
    }

}

void longest(struct xy s[],int a)//坐标组；坐标个数
{
    int t[105],max=0,k=0,time=0;
    for(int i=0;i<105;i++)
    {
        t[i]=1;
    }
    //for(int q=0;q<a;q++)
    //{
    for(int i=0;i<a;i++)//list[i]确定，list[j]进行查找
    {
        for(int j=i;j>=0;j--)
        {
            if(s[i].x1==0&&s[i].x2==0&&s[i].y1==0&&s[i].y2==0) continue;
            else if(s[j].x2==s[i].x1&&s[j].y2==s[i].y1)
            {
                t[i]+=t[j];
                //left(s[],j,a);

                s[i].x1=s[j].x1;
                s[i].y1=s[j].y1;
                s[j].x1=0;
                s[j].x2=0;
                s[j].y1=0;
                s[j].y2=0;
                time++;
            }
            else if(s[j].x1==s[i].x2&&s[j].y1==s[i].y2)
            {
                t[i]+=t[j];
                //left(s[],j,a);
                s[i].x2=s[j].x2;
                s[i].y2=s[j].y2;
                s[j].x1=0;
                s[j].x2=0;
                s[j].y1=0;
                s[j].y2=0;
                time++;
            }


        }
        if(time!=0)
        {
            i--;
        }

        time=0;

    }
    //}

    for(int i=0;i<a;i++)
        {
            if(t[i]>=max)
            {
                max=t[i];
                k=i;
            }

            else continue;
        }
        z=max;
        x=s[k].x1;
        c=s[k].y1;

}
int main()
{
    struct xy list[105];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
    }
    //printf("%d %d %d\n",z,x,c);
    longest(list,n);
    printf("\n");
    /*for(int i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",list[i].x1,list[i].y1,list[i].x2,list[i].y2);
    }*/

    printf("%d %d %d",z,x,c);
    //printf("%d",logest(list));
    return 0;
}
/*
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120

*/









