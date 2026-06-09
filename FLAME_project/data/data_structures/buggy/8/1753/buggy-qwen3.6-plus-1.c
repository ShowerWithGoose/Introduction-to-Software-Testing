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
    putchar(' '); // @@ [The function always prints a trailing space after the number. The expected output format usually requires no trailing space at the end of the line, or specific spacing. More critically, in the DFS traversal `s`, `wrt` is called for every node including the last one, resulting in a trailing space before the newline. While the provided "Buggy Output" shows spaces, strict judges often reject trailing spaces. However, looking at the logic, the main issue is likely how the DFS output is constructed vs BFS. Let's look closer. Actually, the problem description says "separated by spaces". The reference program handles spacing carefully. The buggy program's `wrt` adds a space after EVERY number. This leads to a trailing space at the end of the line. Many online judges consider this a Wrong Answer if they compare strictly or if the newline follows immediately after the last digit in expected output. But wait, looking at the Buggy Output provided in the prompt: `0 1 2 ` (with a trailing space). The Expected Output is `0 1 2` (no trailing space visible, but typically implied). If the judge is strict, the trailing space is an error. Let's look for logical errors first.]
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
    wrt(u); // @@ [This prints the current node followed by a space. In a recursive DFS, this prints nodes in visit order. However, because `wrt` appends a space, the final output line will have a trailing space. If the judge expects no trailing space, this is an error. More importantly, let's check if the traversal logic itself is correct. It marks `vst[q]=1` before recursing, which is standard. It iterates `q` from 0 to `tot-1`, ensuring ascending order. This logic seems correct for DFS sequence generation, aside from the formatting issue.]
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
    putchar(10); // @@ [Prints newline. Combined with `wrt` adding a space after every number, the line ends with "number space newline". Expected is likely "number newline". This trailing space is a common cause for WA in strict formats.]
    
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
            if(x[rt][q]==1) // @@ [Logic Error: `rt` is the index in the queue `qu`, not the vertex ID itself. The adjacency matrix `x` should be indexed by the vertex ID `qu[rt]`, not the queue index `rt`. Here it accesses `x[rt][q]`, which checks edges from vertex `rt` (the queue position) instead of the actual vertex stored at that position. This is a critical semantic error.]
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
    //再输出删除给定顶点后的深度优先遍历顶点序列和广度优先遍历顶点序列
    s1();
    s2();
}