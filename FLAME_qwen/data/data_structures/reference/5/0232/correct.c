//去掉最后为零的项！！     一定要链表么？暴力结构体！！
//debug 技巧：人肉模拟，便于检查出可能的bug!
#include<stdio.h>

typedef struct _xiang{
    int xishu;
    int cishu;
}xiang;
xiang xiang1[100],xiang2[100],ans[10000];


void mutiple(int n1,int n2)
{
    int biao=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            ans[biao].cishu=xiang1[i].cishu+xiang2[j].cishu;
            ans[biao++].xishu=(xiang1[i].xishu)*(xiang2[j].xishu);
            //printf("%d %d %d %d %d %d\n",ans[biao-1].cishu,xiang1[i].cishu,xiang2[j].cishu,ans[biao-1].xishu,xiang1[i].xishu,xiang2[j].xishu);
        }
    }
}
int cmp(const void *p1,const void *p2)//次数从高到低
{
    xiang a=*((xiang *)p1);
    xiang b=*((xiang *)p2);
    if(a.cishu>b.cishu) return -1;
    return 1;
}
int zhenghe(int n3)//任务：相同次数项相加，系数为零的删除，整体赋值！
{
    for(int i=0;i<n3-1;i++)//直接维护n3也可以！
    {
        /*if(ans[i].cishu==ans[i+1].cishu)
        {
            ans[i].xishu+=ans[i+1].xishu;
            for(int j=i+1;j<n3-1;j++)//检查换位的正确性！
                ans[j]=ans[j+1];
            n3--;
        } 好！此处错误作为警醒！i在整合后就加走了，不能继续进行整合！以后整合类子问题，就必须达到不必整合的条件了的时候再往下加一个数！！！
        技巧：if改成while就行了！！并且注意内部有while时要重新将判断条件放进去！！*/
        while(i<n3-1&&ans[i].cishu==ans[i+1].cishu)
        {
            ans[i].xishu+=ans[i+1].xishu;
            for(int j=i+1;j<n3-1;j++)
                ans[j]=ans[j+1];
            n3--;
        }
    }
    for(int i=0;i<n3;i++)
    {
        if(ans[i].xishu==0)
        {
            for(int j=i;j<n3-1;j++)//j=i!!!
                ans[j]=ans[j+1];
            n3--;
        }
    }
    return n3;
}
int main()
{
    char ch;
    int i=0,n1,n2,n3;
    do{
        scanf("%d%d",&xiang1[i].xishu,&xiang1[i].cishu);//不要老是忘了取地址！
        i++;//经验：这种多重操作的不要直接再内部i++!因为赋值操作会迟滞于它，导致数据错位！！！
        //printf("1 %d %d\n",xiang1[i-1].xishu,xiang1[i-1].cishu);
    }while((ch=getchar())!='\n');
    n1=i;
    i=0;
    do{
        scanf("%d%d",&xiang2[i].xishu,&xiang2[i].cishu);
        i++;
        //printf("2 %d %d\n",xiang2[i-1].xishu,xiang2[i-1].cishu);
    }while((ch=getchar())!='\n');
    n2=i;

    mutiple(n1,n2);

   /* for(int i=0;i<n1*n2;i++)
        printf("%d %d ",ans[i].xishu,ans[i].cishu);
        printf("\n");*/
    qsort(ans,n1*n2,sizeof(ans[0]),cmp);

    /*for(int i=0;i<n1*n2;i++)
        printf("%d %d ",ans[i].xishu,ans[i].cishu);
        printf("\n");*/
    n3=zhenghe(n1*n2);

    for(int i=0;i<n3;i++)
        printf("%d %d ",ans[i].xishu,ans[i].cishu);

    return 0;
}

