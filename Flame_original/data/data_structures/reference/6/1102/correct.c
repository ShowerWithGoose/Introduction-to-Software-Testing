#include<stdio.h>

int a[100],i=-1;

int main(int argc, const char * argv[]){
	while(1){
		int flag;
		scanf("%d",&flag);
				
	    if(flag==1){
		    int x;
			scanf("%d",&x);
			
			if(i==99) printf("error ");
			else a[++i]=x;
		}
		
		else if(flag==0){
			if(i==-1) printf("error ");
			else printf("%d ",a[i--]);
		}
		
		else if(flag==-1) break;
	} 
	return 0;
}

