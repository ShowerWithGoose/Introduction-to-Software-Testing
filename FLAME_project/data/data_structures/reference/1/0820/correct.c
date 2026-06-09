#include <stdio.h>
int n;
void prev(int n,int m,int arr[],int ob[]){
	int i,j;
	if(n>=m){
		for(i=0;i<m;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	else {
		for(i=1;i<=m;i++){
			if(ob[i]==0){
				ob[i]=1;
				arr[n]=i;
				prev(n+1,m,arr,ob);
				ob[i]=0;
			}
		}
	}
}
int main (){
	int i,ob[15],arr[15];
	int m;
	scanf("%d",&m);
	for(i=0;i<=m;i++){
		ob[i]=0;
		arr[i]=0;
	}
	prev(0,m,arr,ob);
	return 0;
}

