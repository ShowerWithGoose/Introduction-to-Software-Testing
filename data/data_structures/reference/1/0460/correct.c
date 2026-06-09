#include<stdio.h>
#include<string.h>

int a[20],n,pos[20];
void add(int head,int tail){
	int temp=a[tail];
	for(int i=tail;i>head;i--){
		a[i]=a[i-1];
	}
	a[head]=temp;
}
void turn(int head,int tail){
	int temp=a[head];
	for(int i=head;i<tail;i++){
		a[i]=a[i+1];
	}
	a[tail]=temp;
}
void dfs(int c){
	// freopen("D:\\temp.txt","w",stdout);
	if(c==n) {
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
		return;
	}
	for(int i=c;i<=n;i++){
		add(c,i);
		dfs(c+1);
		turn(c,i);
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	dfs(1);
	return 0;
} 

