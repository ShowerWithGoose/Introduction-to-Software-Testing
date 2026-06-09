#include <stdio.h>
#include <stdlib.h>
struct link{
	int co;
	int po;
	struct link* next;
};
	int coef1[100],coef2[100],anscoef[100000];
	int power1[100],power2[100],anspower[100000];
int main(){
	int a,b,i=0,n=0,m=0,temcoef,tempower;
	while(scanf("%d %d",&a,&b)!=EOF){
		coef1[i]=a;
		power1[i]=b;
		n++;
	//	printf("%d %d\n",coef1[i],power1[i]);
		i++;
		if(getchar()=='\n'){
			break;
		}
	}
	i=0;
	//printf("equation1 over\n");
	while(scanf("%d %d",&a,&b)!=EOF){
		coef2[i]=a;
		power2[i]=b;
		m++;
		//printf("%d %d\n",coef2[i],power2[i]);
		i++;
		if(getchar()=='\n'){
			break;
		}
	}
	i=0;
//	printf("equation2 over\n");//录入完成 
	for(int j=0;j<n;j++){//做乘法！！！ 
		for(int k=0;k<m;k++){
			anscoef[(j)*m+k]=coef1[j]*coef2[k];
			anspower[(j)*m+k]=power1[j]+power2[k];
		}
	}
	for(int j=0;j<m*n;j++){
	//	printf("%d %d\n",anscoef[j],anspower[j]);
	}
	for(int j=0;j<n*m;j++){//排序 
		for(int k=j+1;k<n*m;k++){
			if(anspower[k]>anspower[j]){
				tempower=anspower[j];
				temcoef=anscoef[j];
				anspower[j]=anspower[k];
				anscoef[j]=anscoef[k];
				anspower[k]=tempower;
				anscoef[k]=temcoef;
			}
			else if(anspower[k]==anspower[j]){
				anscoef[j]=anscoef[j]+anscoef[k];
				anscoef[k]=0;
				anspower[k]=0;
			}
		}
	}
	for(int j=0;j<m*n;j++){
		if(anscoef[j]==0){
			continue;
		}
		printf("%d %d ",anscoef[j],anspower[j]);
	}
	return 0;
}

