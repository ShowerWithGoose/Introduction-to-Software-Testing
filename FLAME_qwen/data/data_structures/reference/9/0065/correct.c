#include <stdio.h>
typedef struct a
{
    int x1, y1, x2, y2;
}LINE;
int func(LINE l, LINE m[], int k, LINE chongfu);

int main()
{
    LINE line[100];
    int n, l[100], maxline[100], j, i,lmax = 0;
    scanf("%d", &n);
    for (i = 0; i < n;i++)
    {
        scanf("%d", &line[i].x1);
        scanf("%d", &line[i].y1);
        scanf("%d", &line[i].x2);
        scanf("%d", &line[i].y2);
    }
    for (j = 0; j < n;j++)
        l[j] = func(line[j], line, n, line[j]);
    
    // for(i=0;i<n;i++)
    //     printf("%d:%d ",i+1, l[i]);
    // printf("\n");
    //找最长
    for (j = 0; j < n;j++)
    {
        if(l[j]>lmax)
            lmax = l[j];
    }

    //最长线段组成
    for(i = 0,j = 0; j < n; j++)
    {
        if(l[j]==lmax)
        {
            maxline[i++] = j;
            //printf("第%d条构成最长\n", j+1);
        }
    }
    //找最长连续线段中的起点,首先，这个点只出现一次不会有人连,其次，只有单一坐标的点只有两个,要x和y都小的
    // for (j = 0; j < lmax;j++)
    // {
    //     printf("%d ", maxline[j]);
    // }
    // printf("\n");
    int a[2]={0}, b[2]={0}, c[2]={0}, flag = 0, m;
    for (j = 0; j < lmax;j++)
    {
        flag = 0;
        for (i = 0; i < lmax ;i++)
        {
            if((line[maxline[j]].x1 == line[maxline[i]].x2 && line[maxline[j]].y1 == line[maxline[i]].y2))
            {
                ///起点接了别人终点
                for (m = 0; m < lmax;m++)
                {
                    if(line[maxline[j]].x2 == line[maxline[m]].x1 && line[maxline[j]].y2 == line[maxline[m]].y1)
                    {
                        //printf("线段%d不是边界\n", maxline[j] + 1);
                        flag = -1;//自己终点后面有东西
                        break;
                    }
                }
                if(m==lmax)
                    flag = 1;
            }
            if(flag == -1)
                break;

            else if((line[maxline[j]].x2 == line[maxline[i]].x1 && line[maxline[j]].y2 == line[maxline[i]].y1) )
            {
                //终点接了别人起点
                for (m = 0; m < lmax;m++)
                {
                    //起点留出
                    if(line[maxline[j]].x1 == line[maxline[m]].x2 && line[maxline[j]].y1 == line[maxline[m]].y2)
                    {
                        //printf("线段%d不是边界\n", maxline[j] + 1);
                        flag = -1;
                        break;
                    }
                }
                if(m==lmax)
                    flag = 2;
            }
            if(flag == -1)
                break;
        }
        if(flag == 1)
        {
            b[0] = line[maxline[j]].x2;
            b[1] = line[maxline[j]].y2;
        }
        else if(flag == 2)
        {
            a[0] = line[maxline[j]].x1;
            a[1] = line[maxline[j]].y1;
        }
    }
    if(a[0]<b[0])
    {
        c[0] = a[0], c[1] = a[1];
    }
    else if(a[0]==b[0])
    {
        if(a[1]>b[1])
            c[0] = b[0], c[1] = b[1];
        else
            c[0] = a[0], c[1] = a[1];
    }
    else
        c[0] = b[0], c[1] = b[1];
    printf("\n%d %d %d", lmax, c[0], c[1]);

}

int func(LINE l, LINE m[], int k, LINE chongfu)
{
    int length = 1;
    ////以l为起始线段，m[i]是与他相接的
    for (int i = 0; i < k;i++)
    {      
         ////我的终点等于别人的起点                    我的终点等于别人的终点但 起点不一样                                                 我的起点等于别人的起点但终点不同                                                       我的起点等于别人的终点                          并且新线段不是前一个
        if(((l.x2 == m[i].x1 && l.y2 == m[i].y1) || ((l.x2 == m[i].x2 && l.y2 == m[i].y2) && (l.x1 != m[i].x1 || l.y1 != m[i].y1))  ||   (l.x1 == m[i].x2 && l.y1 == m[i].y2)  || ((l.x1 == m[i].x1 && l.y1 == m[i].y1) && (l.x2 != m[i].x2 || l.y2 != m[i].y2))) &&(m[i].x1!=chongfu.x1||m[i].x2!=chongfu.x2||m[i].y1!=chongfu.y1||m[i].y2!=chongfu.y2))
        {
            //printf("线段%d %d  %d %d的后继第%d条线段\n", l.x1, l.y1, l.x2, l.y2, i + 1);
            length = func(m[i], m, k, l) + length;
        }
    }
    return length;
}
