#include <stdio.h>

int arr[100];
int path[20];
int ret[1000][100];
int used[100];
int op=0;
int pathtop=0;
int size(int *arr1){
	int i=0;
	for(i=0;arr1[i]!=0;i++);
	return i;
}
void put(int *path){
	int i;
	for(i=0;i<size(path);i++){
		ret[op][i]=path[i];
	}
}
void clear(){
	int i;
	for(i=0;i<20;i++){
		path[i]=0;
	}
}
void backtracking(){
	if(size(path)==size(arr)){
		put(path);
		op++; 
		return ;
	}
	int i;
	for(i=0;i<size(arr);i++){
		if(used[i]==1){
			continue;
		}
		path[pathtop++]=arr[i];
		used[i]=1;
		backtracking();
		path[pathtop]=0;
		pathtop--;
		used[i]=0;
	}
}
void printl(int n){
	int i,j;
	for(i=0;i<op;i++){
		for(j=0;j<n;j++){
			printf("%d ",ret[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		arr[i-1]=i;
	}
	backtracking();
	printl(n);
	
	return 0;
} 



