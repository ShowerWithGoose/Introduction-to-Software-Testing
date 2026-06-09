#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int n;
int num[20];
bool used[20];
void f(int x){
	int j;
	if(x>n){
		for(j=1;j<n+1;j++)printf("%d ",num[j]);
		printf("\n");
		return;
	}
	for(j=1;j<n+1;j++){
		if(!used[j]){
			num[x]=j;
			used[j]=true;
			f(x+1);
			num[x]=0;
			used[j]=false;
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
		used[i]=false;
	f(1);
	return 0;
}



