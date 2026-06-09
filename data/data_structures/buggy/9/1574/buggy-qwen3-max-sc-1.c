#include <stdio.h>
#include <string.h>

int duan[104][4];//每段线的坐标
int len[104];//每条线的长度
int a[104];//是否出现过

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    while(i<n)
    {
        len[i]=1;
        for(int j=0;j<4;j++)
        {
            scanf("%d",&duan[i][j]);
        }
        i++;
    }//输入信息
    
    for(int x=0;x<n;x++)
    {
        if(a[x]==0)
        {
            for(int y=0;y<n;y++)
            {
                if(a[y]==0)            
                {
                    if(duan[x][2]==duan[y][0]&&duan[x][3]==duan[y][1])
                    {
                        duan[y][0]=duan[x][0];
                        duan[y][1]=duan[x][1];
                        len[y]=len[x]+len[y];
                        len[x]=0;
                        a[x]=-1;
                    }//右端加
//                    else if(duan[x][0]==duan[y][2]&&duan[x][1]==duan[y][3])
//                    {
//                        duan[y][2]=duan[x][2];
//                        duan[y][3]=duan[x][3];
//                        len[y]=len[x]+len[y];
//                        len[x]=0;
//                        a[x]=-1;
//                    }//左端加
                }
            }
        }
    }
    
    int max=0;
    int b=0;
    for(int u=0;u<n;u++)
    {
        if(len[u]>max)
        {
            b=u;
            max=len[u];
            printf("%d! ",len[u]); // @@ [This debug print statement causes incorrect output format; the problem requires only one line of output with three integers, but this prints extra "! " tokens during the search.]
        }
    }
    printf("%d %d %d",len[b],duan[b][0],duan[b][1]); // @@ [If all segments are isolated (max=1), and multiple segments have len[u]==1, variable 'b' may not be properly initialized to the correct starting segment because the loop updates 'b' only when len[u] > max, not >=. However, the bigger issue is that the algorithm only merges in one direction (right extension), failing to build continuous lines that require left extension or bidirectional chaining.]

    return 0;
}