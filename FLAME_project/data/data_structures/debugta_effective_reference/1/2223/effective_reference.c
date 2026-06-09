#include<stdio.h>
int n,num[10],m[10];
void src(int pt){
	int i;
	if(pt==n)
		{
		for(i=0;i<n;i++)
			printf("%d ",num[i]);
		printf("\n");
	}
	else{
		for(i=0;i<n;i++)
			if(!m[i]){
				num[pt]=i+1;
				m[i]=1;
				src(pt+1);
				m[i]=0;
			}
		}
	return;
}
int main(){
	scanf("%d",&n);
	src(0);
	return 0;
}



