#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#define clear(a) memset(a,0,sizeof(a))
int main()
{
    int a1[100][100]={{0}},a2[100][100]={{0}},pt[100];
    int V_num,E_num,V_del,V_mov,cnt,stack[100],queue[100],sta_num,que_be,que_af,que_br,flag;
    scanf("%d%d",&V_num,&E_num);
    int i1,i2,e1,e2;
    for(i1=0;i1<E_num;i1++)
    {
        scanf("%d%d",&e1,&e2);
        a1[e1][e2]=1;
        a1[e2][e1]=1;
        a2[e1][e2]=1;
        a2[e2][e1]=1;
    }
    scanf("%d",&V_del);

    clear(pt);
    clear(stack);
    cnt=1;
    sta_num=1;
    V_mov=0;
    stack[0]=0;
    pt[0]=1;
    printf("0 ");
    while(cnt!=V_num)
    {
        flag=0;
        for(i1=0;i1<V_num;i1++)
        {
            if(a1[V_mov][i1]==1 && pt[i1]==0)
            {
                printf("%d ",i1);
                stack[sta_num]=i1;
                sta_num++;
                cnt++;
                flag=1;
                pt[i1]=1;
                V_mov=i1;
                break;
            }
        }
        if(flag==0)
        {
            sta_num--;
            V_mov=stack[sta_num-1];
        }
    }
    putchar(10);

    clear(pt);
    clear(queue);
    que_be=0;
    que_af=1;
    queue[0]=0;
    pt[0]=1;
    while(que_af!=V_num)
    {
        for(i1=0;i1<V_num;i1++)
        {
            if(a1[queue[que_be]][i1]==1 && pt[i1]==0)
            {
                queue[que_af]=i1;
                que_af++;
                pt[i1]=1;
            }
        }
        que_be++;
    }
    for(i1=0;i1<V_num;i1++)
    {
        printf("%d ",queue[i1]);
    }
    putchar(10);

    clear(pt);
    clear(stack);
    cnt=2;
    sta_num=1;
    if(V_del!=0)
    {
        V_mov=0;
        stack[0]=0;
        pt[0]=1;
        printf("0 ");
        pt[V_del]=1;
    }
    else
    {
        V_mov=1;
        stack[0]=1;
        pt[1]=1;
        printf("1 ");
        pt[V_del]=1;
    }
    while(cnt!=V_num)
    {
        flag=0;
        for(i1=0;i1<V_num;i1++)
        {
            if(a1[V_mov][i1]==1 && pt[i1]==0)
            {
                printf("%d ",i1);
                stack[sta_num]=i1;
                sta_num++;
                cnt++;
                flag=1;
                pt[i1]=1;
                V_mov=i1;
                break;
            }
        }
        if(flag==0)
        {
            sta_num--;
            V_mov=stack[sta_num-1];
        }
    }
    putchar(10);

    clear(pt);
    clear(queue);
    que_be=0;
    que_af=1;
    if(V_del!=0)
    {
        queue[0]=0;
        pt[0]=1;
        pt[V_del]=1;
    }
    else
    {
        queue[0]=1;
        pt[1]=1;
        pt[V_del]=1;
    }
    while(que_af+1!=V_num)
    {
        for(i1=0;i1<V_num;i1++)
        {
            if(a1[queue[que_be]][i1]==1 && pt[i1]==0)
            {
                queue[que_af]=i1;
                que_af++;
                pt[i1]=1;
            }
        }
        que_be++;
    }
    for(i1=0;i1<V_num-1;i1++)
    {
        printf("%d ",queue[i1]);
    }
    putchar(10);

    return 0;
}
