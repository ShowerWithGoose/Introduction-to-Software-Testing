#include<stdio.h>
#include<strings.h>

int x1[100],x2[100],y1[100],y2[100];

int srch(int x1[],int y1[],int x,int y,int n)
{
    int i = 0;
    while((x1[i] != x || y1[i] != y) && i < n)
    {
        i++;
    }
    if(i == n) return -1;
    return i;
}

int main()
{
    int n,max_cnt=0,tmp_cnt=0,op,tmp;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for(int i = 0 ; i < n ; i ++)
    {
        op = srch(x1,y1,x2[i],y2[i],n);
        while(op!=-1)
        {
            tmp_cnt++;
            op = srch(x1,y1,x2[op],y2[op],n);
        }
        if(tmp_cnt > max_cnt)
        {
            max_cnt = tmp_cnt;
            tmp = i;
        }
        tmp_cnt = 0;
    }
    printf("%d %d %d" , ++max_cnt,x1[tmp],y1[tmp]);
    system("pause");
    return 0;
}
