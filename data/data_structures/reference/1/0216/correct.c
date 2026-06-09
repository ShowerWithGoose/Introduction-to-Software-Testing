#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[11]={0,1,2,3,4,5,6,7,8,9,10},b[11]={};
void x(int n,int m,int k,int y[]){
	int e[11]={};
	for(int i=0;i<=n;i++){
		e[i]=y[i];
	}
	e[k]=0;b[m]=k;
	if(m!=1){
		for(int i=1;i<=n;i++){
		    if(e[i]!=0) {
		    	for(int i=m-1;i>1;i--) b[i]=0;
		    	x(n,m-1,i,e);
			}
	    }
	}
	else for(int j=n;j>0;j--){
		printf("%d ",b[j]);
		if(j==1) {
		   printf("\n");
		   
		   }	
		}
	}

    
int main(){
    int o;
    scanf("%d",&o);
    for(int i=1;i<=o;i++){
    	x(o,o,i,a);
	}
}

