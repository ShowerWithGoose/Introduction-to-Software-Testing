#include <stdio.h>
int a[101];
int j,i=0;
int main() {
	for(j;j<1;j--) {
		int op;
		scanf("%d",&op);
		if(op==1) {
			if(i==100)
				printf("error ");
			else 
				{i++;
				scanf("%d ",&a[i]);}
			}	
		if(op==0) {
			if(i==0)
				printf("error ");
			else 
				{printf("%d ",a[i]);
				i--;}
			}	
		if(op==-1)
		break;
	}
	

	return 0;
}

