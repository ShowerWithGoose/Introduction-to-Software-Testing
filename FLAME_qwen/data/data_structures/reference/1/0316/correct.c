#include<stdio.h>
int visit[100]={0};
int number[5];//存储搜索到的排列 
void dfs(int index,int n)  
{  
	int i=0,j=0; 
    if(index==n)  //index的作用是搜索到足够的数字就输出排列数 
    {
        for(j=0;j<n;j++)
            printf("%d ",number[j]);
	printf("\n"); 
        return ;  
    }  
    for(i=1;i<=n;i++)  
    {  
        if(visit[i]==0)  
        {  
            visit[i]=1;  //标记这个数已记录，不应再取 
            number[index]=i;  //取数 
            dfs(index+1,n);  //搜索下一个可取的数 
            visit[i]=0;  //解除标记，状态变回可取 
        }  
    }  
}  
int main()  
{   
	int n=0;
	scanf("%d",&n);
    dfs(0,n);  
    return 0;  
}

