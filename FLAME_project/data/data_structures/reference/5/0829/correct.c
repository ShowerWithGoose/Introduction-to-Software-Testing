#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[100],b[100],c[100],d[100],i=0,e[100],f[100],n,m,j=0,k=0,l,x;
	while(scanf("%d%d",&a[i],&b[i])){
		i++;
		if(getchar()=='\n')break;
	}
	n=i;
	while(scanf("%d%d",&c[j],&d[j])){
		j++;
		if(getchar()=='\n')break;
	}
	m=j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++,k++){
			e[k]=a[i]*c[j];
			f[k]=b[i]+d[j];
		}
	}
	for(i=0;i<k;i++){
		for(j=0;j<k-1;j++){
			if(f[j]<f[j+1]){
				l=f[j];
				f[j]=f[j+1];
				f[j+1]=l;
				l=e[j];
				e[j]=e[j+1];
				e[j+1]=l;
			}
		}
	}
	for(i=0;i<k;i++){
		x=e[i];
		for(j=i;j<k;j++){
			if(f[j]==f[j+1]){
				x+=e[j+1];
			}
			else break;
		}
		i=j;
		printf("%d %d ",x,f[i]);
	}
	return 0;
}

