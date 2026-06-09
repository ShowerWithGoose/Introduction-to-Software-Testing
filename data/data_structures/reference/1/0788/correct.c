#include<stdio.h>
int c[10],l;
void f(int a[],int n){
	int i,b[n];
	if(n<2){
        c[l-1]=a[0];
        for(i=0;i<l;i++)
        printf("%d ",c[i]);
        printf("\n");
    }
	else{
		int j=0;
		for(i=0;i<n;i++){
			c[l-n]=a[i];
			int k=0;		
			for(j=0;j<n;j++){
				if(j!=i){
	    	    	b[k]=a[j];
	    	    	k++;
	        	}
	    		else
		    	continue;    						
			}
			f(b,n-1);			
		}
	}
}
int main(){
	int a[10],i;
	scanf("%d",&l);
	for(i=0;i<l;i++)
	a[i]=i+1;
	f(a,l);
}



