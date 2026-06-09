#include<stdio.h>
int b[15]={0};
int a[15];
void pailie(int x,int y);

	int n;
int main(){
    
	scanf("%d",&n);
	pailie(0,n);
	return 0;
} 
void pailie(int x,int y){
    int i;
    if(y==0){
        for(i=0;i<n-1;i++){
        	printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
        //return;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			a[x]=i;
			pailie(x+1,y-1);
			b[i]=0;
		}
	}
}


