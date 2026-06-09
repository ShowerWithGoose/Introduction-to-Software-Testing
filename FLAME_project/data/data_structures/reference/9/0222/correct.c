#include <stdio.h>
int n,a[10000][5];
void clean(int x){
	int i;
	for(i=x;i<n;i++){
		a[i][0]=a[i+1][0];
		a[i][1]=a[i+1][1];
		a[i][2]=a[i+1][2];
		a[i][3]=a[i+1][3];
		a[i][4]=a[i+1][4];
	}
	--n;
}
int main(){
	int i,j,k,max;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i][0]=1;
		scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	}
    for(k=1;k<=n;k++){
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			if((a[i][1]==a[j][1])&&(a[i][2]==a[j][2])){
				a[i][1]=a[j][3];
				a[i][2]=a[j][4];
				a[i][0]+=a[j][0];
				clean(j);
				--j;
				continue;
			}
			if((a[i][1]==a[j][3])&&(a[i][2]==a[j][4])){
				a[i][1]=a[j][1];
				a[i][2]=a[j][2];
				a[i][0]+=a[j][0];
				clean(j);
				--j;
				continue;
			}
			if((a[i][3]==a[j][1])&&(a[i][4]==a[j][2])){
				a[i][3]=a[j][3];
				a[i][4]=a[j][4];
				a[i][0]+=a[j][0];
				clean(j);
				--j;
				continue;
			}
			if((a[i][3]==a[j][3])&&(a[i][4]==a[j][4])){
				a[i][3]=a[j][1];
				a[i][4]=a[j][2];
				a[i][0]+=a[j][0];
				clean(j);
				--j;
				continue;
			}			
		}
	}	
}
	max=1;
	for(i=2;i<=n;i++){
		if(a[i][0]>a[max][0])
		max=i;
	}
	printf("%d ",a[max][0]);
	if(a[max][1]<a[max][3])
	    printf("%d %d",a[max][1],a[max][2]);
	else
	    printf("%d %d",a[max][3],a[max][4]);
	return 0;  
}

