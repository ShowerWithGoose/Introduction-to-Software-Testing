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
        putchar(' '); // @@ [This prints a space even after the last number, causing trailing space which may lead to presentation error, but more critically, in BFS/DFS output format, each line must have space-separated numbers with no trailing space. However, the main logical error is elsewhere.]
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
    putchar(' '); // @@ [Same issue: always appends a trailing space after every number, including the last one in the sequence. This violates typical output requirements (though sometimes tolerated), but the real bug is in traversal logic.]
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
    wrt(u); // @@ [This prints the current vertex immediately upon entering s(), but note that in s1(), vertex 0 is already printed before calling s(0). So vertex 0 gets printed twice: once in s1() via wrt(0) implicitly through st setup? Wait — actually, look at s1(): it sets st[0]=0 and then calls s(0). But inside s(0), the first thing is wrt(0). However, in s1(), there's no explicit print of 0 before calling s(0). Wait — no: s1() does NOT print anything before calling s(0). It only sets vst[0]=1 and then calls s(0). And s(0) starts by printing u=0. So that’s correct. BUT: the problem is that in DFS, we must visit neighbors in ascending order. However, the loop in s() goes from q=0 to q<tot, which is ascending — so that seems okay. However, the real issue is that after deleting the vertex, the total number of vertices considered should exclude the deleted one, but the code still iterates up to 'tot' (original n), including the deleted vertex index, which has been zeroed out in adjacency matrix — that part is okay. However, there's a deeper flaw...]
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
    
    s(0); // @@ [This is correct: starts DFS from 0, which prints 0 first, then recurses. But note: the sample expects "0 1 3 6 8 4 2 5 7" before deletion. However, the DFS implementation visits neighbors in ascending order (q from 0 to tot-1), so from 0, neighbors are 1 and 2 (in sample input). Since 1 < 2, it goes to 1 first — correct. From 1, neighbors: 0 (visited), 3,4,8. Ascending: 3,4,8 → so goes to 3 first — correct. So DFS logic seems fine. Then why failure? Let's check BFS.]
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
        for(int q=0;q!=tot;q++) // @@ [Here's the critical error: when traversing from the current node 'rt' (which is an index into qu[]), the code uses 'rt' as the vertex number. But 'rt' is the queue index, not the vertex! It should be: int current = qu[rt]; then iterate over neighbors of 'current'. Instead, it's using 'rt' (which starts at 0, then 1,2,...) as the vertex id. So in first iteration, rt=0 → uses vertex 0 (correct). Then rt=1 → uses vertex 1 (but qu[1] might be 1 or 2 depending on order). In sample: after 0, neighbors are 1 and 2 → so qu becomes [0,1,2], ts=3, rt=0→1→2. When rt=1, it processes vertex 1 (because qu[1]=1) — but the code uses 'rt' (which is 1) as the vertex, which accidentally matches. But what if the queue had [0,2,1]? Then when rt=1, it would process vertex 1 (qu[1]=2), but the code uses rt=1 as vertex id → wrong! So this is a fundamental bug: using queue index 'rt' instead of the actual vertex stored in qu[rt].]
        {
            if(x[rt][q]==1) // @@ [Should be x[qu[rt]][q] == 1]
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