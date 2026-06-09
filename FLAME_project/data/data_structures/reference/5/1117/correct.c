#include<stdio.h>
struct dxs
{
	int an;
	int n;
};
int main(){
	struct dxs a1[20],a2[20],a3[400];
	char c;
	int i,j,k=0,n1,n2,n3;
	for(i=0;;i++){
		scanf("%d%d",&a1[i].an,&a1[i].n);
		if(getchar()=='\n'){
			break;
		}
	}
	for(j=0;;j++){
		scanf("%d%d",&a2[j].an,&a2[j].n);
		if(getchar()=='\n'){
			break;
		}
	}
	n1=i+1; n2=j+1;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			a3[k].an=a1[i].an*a2[j].an;
			a3[k].n=a1[i].n+a2[j].n;
			k+=1;
		}
	}
	for(i=0;i<k;i++){
	    for(j=i+1;j<k;j++){
	    	if(a3[i].n==a3[j].n&&a3[j].an!=0){
	    		a3[i].an+=a3[j].an;
	    		a3[j].an=0; a3[j].n=0; 
			}
		}
	}
	n3=k;
	int t1,t2;
	while(n3){
		for(i=0;i<n3;i++){
			if(a3[i].n<a3[i+1].n){
				t1=a3[i].an; t2=a3[i].n;
				a3[i].an=a3[i+1].an; a3[i].n=a3[i+1].n;
				a3[i+1].an=t1; a3[i+1].n=t2;
			}
		}
		n3-=1;
	}
	for(i=0;i<k;i++){
		if(a3[i].an!=0){
			printf("%d %d ",a3[i].an,a3[i].n);
		}
	}
	return 0;
}

