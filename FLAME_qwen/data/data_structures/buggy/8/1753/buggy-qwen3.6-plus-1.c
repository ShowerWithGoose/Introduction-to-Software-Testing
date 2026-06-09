#include<stdio.h>
int r()
{
    int x_=0,y_=1;
    char z_=getchar();
    while(z_<'0'||z_>'9')
    {
        if(z_=='-')
        {
            y_=-1;
        }
        z_=getchar();
    }
    while(z_>='0'&&z_<='9')
    {
        x_=x_*10+z_-'0';
        z_=getchar();
    }
    return x_*y_;
}
void wrt(int _x)
{
    if(_x==0)
    {
        putchar('0');
        putchar(' ');
        return;
    }
    char _X[600];
    int tp=0;
    if(_x>0&&0<_x)
    {
        tp=_x;
    }
    else
    {
        tp=-_x;
    }
    if(_x<0&&0>_x)
    {
        putchar('-');
    }
    int tot=0;
    for(;tp!=0;)
    {
        _X[tot]=tp%10+'0';
        tp/=10;
        tot++;
    }
    for(;tot!=0;)
    {
        tot--;
        putchar(_X[tot]);
    }
    putchar(' ');
}
int tot;//顶点个数
int tot0;//边的个数
int tv;
int x[133][133];
int vst[133];
int st[133];//深度优先遍历
int qu[133];//广度优先遍历
int top;
int rt;
int ts;
//无论何种遍历，都是从编号为0的顶点开始遍历，访问相邻顶点时按照编号从小到大的顺序访问；
int s(int u)
{
    wrt(u);
    for(int q=0;q!=tot;q++)
    {
        if(x[u][q]==1)
        {
            if(vst[q]==0)
            {
                vst[q]=1;
                s(q);
            }
        }
    }
    return 0;
}
int s1()//深度优先遍历
{
    
    for(int q=0;q!=133;q++)
    {
        vst[q]=0;
    }
    for(int q=0;q!=133;q++)
    {
        st[q]=-1;
    }
    top=0;
    
    st[0]=0;
    top++;
    vst[0]=1;
    
    s(0);
    putchar(10);
    
    return 0;
    
}
int s2()//广度优先遍历
{
    
    for(int q=0;q!=133;q++)
    {
        vst[q]=0;
    }
    for(int q=0;q!=133;q++)
    {
        qu[q]=-1;
    }
    ts=0;
    rt=0;
    
    qu[ts]=0;
    ts++;
    vst[0]=1;
    for(;;)
    {
        if(rt==ts)
        {
            break;
        }
        for(int q=0;q!=tot;q++)
        {
            if(x[rt][q]==1) // @@ [Error: rt is the index of the queue head, not the vertex number. It should be x[qu[rt]][q] to correctly access the adjacency matrix of the current vertex being processed.]
            {
                if(vst[q]==0)
                {
                    vst[q]=1;
                    qu[ts]=q;
                    ts++;
                }
            }
        }
        rt++;
    }
    for(int q=0;q!=ts;q++)
    {
        wrt(qu[q]);
    }
    putchar(10);
    
    return 0;
    
}
int main()//无向图
{
    tot=r();//先从标准输入中输入图的顶点个数和边的个数
    tot0=r();
    for(int q=0;q!=tot0;q++)//用边两端的顶点编号表示一条边
    {
        int u=r();
        int v=r();
        x[u][v]=1;
        x[v][u]=1;
    }
    tv=r();
    //分行输出各遍历顶点序列，顶点编号之间以一个空格分隔
    //先输出删除给定顶点前的深度优先遍历顶点序列和广度优先遍历顶点序列
    s1();
    s2();
    //删除的顶点编号不为0
    for(int q=0;q!=tot;q++)
    {
        x[tv][q]=0;
    }
    for(int q=0;q!=tot;q++)
    {
        x[q][tv]=0;
    }
    //再输出删除给定顶点后的深度优先遍历顶点序列和广度优先遍历序列
    s1();
    s2();
}