#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
	int a[100]={0},b[100]={0},c[100]={0},d[100]={0};int n1,n2;int y=0,y1=0;
	char q;
	int i=0;
	do{
		scanf("%d%d%c",&a[i],&b[i],&q);
		i++;
	}while(q!='\n');
	n1=i;
    i=0;
	do{
		scanf("%d%d%c",&c[i],&d[i],&q);
		i++;
	}while(q!='\n');
	n2=i;
	int e[100],f[100];
	for(i=0;i<n1;i++){
		for(y=0;y<n2;y++){
			e[y1]=a[i]*c[y];
			f[y1]=b[i]+d[y];
			y1++;
		}
	}int qew,qwe;
	for(y=0;y<y1;y++){for(i=0;i<y1-1;i++){
		if(f[i]<f[i+1]){
			qew=f[i];
			f[i]=f[i+1];
			f[i+1]=qew;
			qwe=e[i];
			e[i]=e[i+1];
			e[i+1]=qwe;
		}
	}
	}int q1=0;
	int a1[100],a2[100];
	a1[0]=e[0];a2[0]=f[0];
	for(i=1;i<y1;i++){
		if(f[i]==a2[q1]){
			a1[q1]=a1[q1]+e[i];
		}
		else{
			q1++;
			a1[q1]=e[i];
			a2[q1]=f[i];
		}
	}
	for(i=0;i<=q1;i++){
		printf("%d %d ",a1[i],a2[i]);
	}
	return 0;
}

