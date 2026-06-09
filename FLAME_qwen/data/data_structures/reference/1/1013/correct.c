#include<stdio.h>
#define MAX 10
int whether_used[MAX]={0};
char arrange[MAX]; 
void arr(int n,int m,int k){
	int i, j;
	if(n==0){
		arrange[m]='\0';
		for(j=0;j<m;j++){
			printf("%c ",arrange[j]);
		}
		printf("\n");
		return;
	}
	for(i=0;i<k;i++){
		if(whether_used[i]==0){
			whether_used[i]=1;
			arrange[m]='0'+i+1;
			arr(n-1,m+1,k);
			whether_used[i]=0;
		}
	}
	
}
int main(){
	int n, m, k;
	scanf("%d",&n);
	m=0;k=n;
	arr(n,m,k);
	return 0;
}

