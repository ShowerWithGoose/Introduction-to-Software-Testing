#include <stdio.h>
int a[11],sp[11];
int n;
void Cnn(int x){
	int i;
	if(x==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",a[i]);	
		}
		printf("\n");
		return;
	}
	
	for(i=1;i<=n;++i){
		if(sp[i]==0){
			sp[i]=1;
			a[x]=i;
			Cnn(x+1);
			sp[i]=0;
			a[x]=0;
		}
	}
	
}
int main(){
	scanf("%d",&n);
	int i;	
	for(i=1;i<=n;i++){
		a[i]=0;
		sp[i]=0;
	}
	
	Cnn(1);	
	return 0;
}



