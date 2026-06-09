#include<stdio.h>
int main(){
	int y[300],n[105];
	int i,j,k=0;
	for(i=1;;i++){
		scanf("%d",&y[i]);
		if(y[i]==-1)
			break;
	}
	for(j=1;j<i;j++){
		if(y[j]==1){
			k++;
			n[k]=y[j+1];	
		}
		else if(y[j]==0&&k>0){
			printf("%d ",n[k]);
			k--;
		}
		else if(y[j]==0&&k<=0){
			printf("error ");
		}
	}
	return 0;
}

