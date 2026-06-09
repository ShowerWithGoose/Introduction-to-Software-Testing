#include<stdio.h>
int a[10],n;
void f(int a[],int l){
	int i,b[l];
	if(l<2){
        a[n-1]=a[0];
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
    }
	else{
		int i=0;
		for(i=0;i<l;i++){
			a[n-l]=a[i];
			int k=0;		
			for(i=0;i<l;i++){
				if(i!=i){
	    	    	b[k]=a[i];
	    	    	k++;
	        	}
	    		else
		    	continue;    						
			}
			f(b,l-1);			
		}
	}
}
int main(){
	int a[10],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	a[i]=i+1;
	f(a,n);
}



