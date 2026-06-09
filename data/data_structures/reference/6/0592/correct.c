#include<stdio.h>
int main(){
	int i=0,j=0,a[105],b[105];
	scanf("%d",&a[i]);
	while(a[i]!=-1){
		if(a[i]==1){
			i++;
			scanf("%d",&a[i]);
			b[j++]=a[i];
		}
		if(a[i]==0){
			i++;
			if(j==0)
			printf("error ");
			if(j!=0){
				printf("%d ",b[--j]);
			}
		}
		scanf("%d",&a[i]);
	}
	return 0;
}

