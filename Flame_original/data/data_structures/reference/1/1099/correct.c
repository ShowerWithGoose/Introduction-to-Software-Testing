	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	#include<string.h>
	#include<ctype.h>
	#include<stdio.h>
	#ifndef bool
	#define bool int
	#endif
	#ifndef true
	#define true 1
	#endif
	#ifndef false
	#define false 0
	#endif 
	
	int n,ans[15],used[15];
void dfs(int x)
{
    int i;
    if(x>n){
    	printf("%d",used[1]);
        for(i=2;i<=n;i++){
   			printf("%2d",used[i]);}
   			puts("");
        return;
		
    }
    for(i=1;i<=n;i++)
    {
        if(!ans[i])
        {	used[x]=i;
            ans[i]=1;
            dfs(x+1);//填下一个
            ans[i]=0;//回溯
        }
    }
}
int main()
{
	scanf("%d",&n); 
    dfs(1);
    return 0;
}

