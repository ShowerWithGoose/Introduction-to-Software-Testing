#include <stdio.h>
int main(){
	int n;
 	scanf("%d",&n);
 	int a[1000];
	int b[1000];
	if (n==1){
		printf("1");
	}
	else {
		
	int i=1;
 	for (i=1; i<n; i++){
 		b[i] = i;
 		printf("%d ", i);
 		
	}
	b[i] = i;
	printf("%d\n", i);
	
		int j=0, j1=0, k=0, m=0, flag=0;
		while (flag==0){
			
		
		for (j=n; j-1>0; j--){
			flag=1;
			if (j-1>0 && b[j] > b[j-1]){
				flag = 0;
				int tmp=0, tmp1 = 0;
				tmp = b[j];
				j1 = j;
				tmp1 = j1;
				for (j1 = j; j1 <= n; j1++){
					if (b[j1] > b[j-1] && b[j1] < tmp){
						
						tmp = b[j1];
						tmp1 = j1;
					}
					
				}
				
				b[tmp1] = b[j-1];
				b[j-1] = tmp;
				break;
				
				
			}
		}
			if (flag == 0){
			
			for (k=n; k>j; j++, k--){
				int tmp2=0;
				tmp2 = b[j];
				b[j] = b[k];
				b[k] = tmp2;
			}
			for (m=1; m<n; m++){
				printf("%d ", b[m]);
				
			}
			printf("%d\n", b[m]);
			}
			
			}
		}
			
			
			
		
	
		
		
	
	
	return 0;
}

