#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int first[300];
int next[1000];
int u[1000],v[1000];
int book[300];
int a[300][300];
int quene[1000];
int t=-3;
int n;
void swap(int l,int r)
{
    int p;
    p=u[l];
    u[l]=u[r];
    u[r]=p;
    p=v[l];
    v[l]=v[r];
    v[r]=p;
}

void shendu(int k)  //深度搜索
{
    int m;
    if (book[k]==1||k==t) return;
    printf("%d ",k);
    book[k]=1;
    m=first[k];
    while (m!=-1)
    {
      shendu(v[m]);
      m=next[m];
    }
}

void guangdu(int k)  //广度搜索
{
    int head=0,tail=-1,queue[10001],temp,j;
    queue[++tail]=k,book[k]=1;
    while(head<=tail)
    {
        temp=queue[head++];
        printf("%d ", temp);
        for(j=0;j<=n-1;j++)
        {
            if(book[j]==0&&a[temp][j]==1&&j!=t)
            {
                queue[++tail]=j;
                book[j]=1;
            }
        }
    }
    return;
}

int main() {
    int m;
    memset(first,-1,sizeof (first));
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    int i,k,j;
    for (i=1;i<=m;i++)
    {scanf("%d%d",&u[i],&v[i]);
        a[u[i]][v[i]]=1;
        a[v[i]][u[i]]=1;}

    for (i=m+1;i<=2*m;i++)
    {
        u[i]=v[i-m];
        v[i]=u[i-m];
    }

    for (i=1;i<=2*m-1;i++)  //排序
    {
        for (j=2;j<=2*m-i+1;j++)
        {
            if (u[j-1]<u[j])
                swap(j-1,j);
            else if (u[j-1]==u[j]&&v[j-1]<v[j])
                swap(j-1,j);
        }
    }

    for (i=1;i<=2*m;i++)    //构建邻接表
    {
        next[i]=first[u[i]];
        first[u[i]]=i;
    }

    memset(book,0,sizeof (book));
    shendu(0);
    printf("\n");
    memset(book,0,sizeof (book));
    guangdu(0);
    printf("\n");
    scanf("%d",&t);
    memset(book,0,sizeof (book));
    shendu(0);
    printf("\n");
    memset(book,0,sizeof (book));
    guangdu(0);
    printf("\n");
    return 0;
}

