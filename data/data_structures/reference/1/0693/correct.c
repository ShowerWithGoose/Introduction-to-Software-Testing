#include <stdio.h>
int vis[20];
void full_array(int *ans,int n,int x);
int main (){
	int n,i;
	int ans[20]={0};
	scanf("%d",&n);
	full_array(ans,n,1);
	return 0;
} 
 
void full_array(int *ans,int n,int x)
{  
 int i;
 if(x==n+1){
 	for(i=1;i<x;i++){
 		printf("%d ",ans[i]);
	 }
	 printf("\n");
	 return;
 }

for(i=1;i<=n;i++){   //此处i指每一个位置上可供选择的数 
	if(vis[i]==0){   //如果在这一层未被用过 ，层x指第几个位置 
		vis[i]=1;
		ans[x]=i;    //选定这一层的此位置数为i 
		full_array(ans,n,x+1); 
		vis[i]=0;
	}
}
}

