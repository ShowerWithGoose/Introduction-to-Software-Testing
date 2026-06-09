#include <stdio.h>
int main(){
	int a[100];
	int c=0,n,i;
	for(i=0;c!=-1;){
		scanf("%d",&c);
		if(c==1){
			scanf("%d ",&a[i]);
			i++;
			continue;
		}
		if(c==0&&i>0){
			i--;
			printf("%d ",a[i]);
			a[i]=0;
			continue;
		}
		if(c==0&&i==0){
			printf("error ");
		}
	} 

	return 0;
}

