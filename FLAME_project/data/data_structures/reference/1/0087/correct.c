#include <stdio.h>
int A[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,};
int n;
void full(int *a, int n1);
int main()
{
	
	scanf("%d", &n);
	full(A, n);
}

void full(int *a, int n1)
{
	if (n1==1){
		for(int i=0; i<n; i++){
			printf("%d ", A[i]);
		}
		putchar('\n');
	}
	else {
		int tmpa[20];
		for(int i=0; i<n; i++){
			tmpa[i] = a[i];
		}
		
		for (int i=0; i<n1; i++){
			int tmp = a[i];
			for (int j=i; j>0; j--){
				a[j] = a[j-1];
			}
			a[0] = tmp;
			full(a+1, n1-1);
			for(int i=0; i<n; i++){
			a[i] = tmpa[i];
		}
		}
	}
}
