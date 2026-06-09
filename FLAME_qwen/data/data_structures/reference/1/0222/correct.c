#include <stdio.h>
int n,i,p,a[11]={0},b[11];
void Arrangement(int p){
	for(b[p]=1;b[p]<=n;b[p]++){
		if(a[b[p]]!=1){
		    a[b[p]]=1;
		    if(p<n)
			    Arrangement(p+1);	
		    else{
		    	for(i=1;i<=n;i++)
		            printf("%d ",b[i]);
	            printf("\n");
			}
		    a[b[p]]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	Arrangement(1);
	return 0;
}

