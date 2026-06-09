#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define eps 1e-10
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define arraynum(x) (sizeof(x)/sizeof(x[0]))
#define MAXLINE 1024
struct line
{
    int x1,y1;
    int x2,y2;
};
void bubblesort(struct line s[],int linenum);
int main()
{
    struct line s[100];
    int linenum;
    int i=0,j=0;
    int maxline=0,max_x=0,max_y=0;
    int curline=0,curpos;

    scanf("%d",&linenum);
    for(i=0;i<linenum;i++)
    {
        scanf("%d %d %d %d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
    }
    bubblesort(s,linenum);

    for(i=0;i<linenum;i++)
    {
        curline=1;curpos=i;
        for(j=i+1;j<linenum;j++)
        {
            if(s[j].x1==s[curpos].x2&&s[j].y1==s[curpos].y2)
            {
                curline++;
                curpos=j;
            }
        }
        if(curline>maxline)
        {
            max_x=s[i].x1;
            max_y=s[i].y1;
            maxline=curline;
        }

    }

    printf("%d %d %d",maxline,max_x,max_y);
    return 0;
}
void bubblesort(struct line s[],int linenum)
{
    int i,j,flag;
    struct line hold;
    for(i=0;i<linenum-1;i++)
    {
        flag=0;
        for(j=0;j<linenum-i-1;j++)
        {
            if(s[j].x1>s[j+1].x1)
            {
                hold=s[j];
                s[j]=s[j+1];
                s[j+1]=hold;
                flag=1;
            }
        }
        if(flag==0) break;
    }
}

