#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	if(n==1)
		printf("1");
	else if(n==2)
		printf("1 2\n2 1");
	else if(n==3)
		printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1");
	else if(n==4){
		int i,j,k,l;
		for (i = 1; i <= 4; i++) {
			for (j = 1; j <= 4; j++) {
				for (k = 1; k <= 4; k++) {
					for (l = 1; l <= 4; l++) {
						if ((i != j) && (j != k) && (i != k) && (i != l) && (j != l) && (k != l)) printf("%d %d %d %d\n",i,j,k,l);
					}
				}
			}
		}
	}
	else{
		int i,j,k,l,m;
		for (i = 1; i <= 5; i++) {
			for (j = 1; j <= 5; j++) {
				for (k = 1; k <= 5; k++) {
					for (l = 1; l <= 5; l++) {
						for (m = 1; m <= 5; m++) {
							if ((i != j) && (j != k) && (i != k) && (i != l) && (j != l) && (k != l) && (i != m) && (j != m) && (k != m) && (l != m)) 
								printf("%d %d %d %d %d\n",i,j,k,l,m);
						}
					}
				}
			}
		}
	}
} 

