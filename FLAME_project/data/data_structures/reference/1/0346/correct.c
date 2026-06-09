#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 3628800
char a[maxn + 1][10];
int cmp(const int *A, const int* B){
    return strcmp(A, B);
}

int f(int n){
    if(n==1)
        return 1;
    return n * f(n - 1);
}

int swap(char *p, char *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void swap_2(int n){
	int i;
	for(i=n-2;i>=0;i--){
		if(a[0][i]<a[0][i+1]) break;
	}
	int j;
	int temp=i+1;
	for(j=i+1;j<n;j++){
		if(a[0][j]>a[0][i]&&a[0][j]<a[0][temp]){
			temp=j;
		}
	}
	swap(&a[0][i],&a[0][temp]);
    int k=i+1;
	j--;
	for (k; k < j;k++){
		swap(&a[0][k], &a[0][j]);
		j--;
	}
}
int main(){
    int n,i,j;
    scanf("%d", &n);
    int k = f(n);
    for (i = 0; i < n;i++){
        a[0][i] = i + '0';
    }
    for (i = 0; i < k - 1; i++)
    {
        swap_2(n);
        strcpy(a[i + 1], a[0]);
    }
    for (i = 0; i < n;i++){
        a[0][i] = i + '0';
    }
    qsort(a, k, sizeof(a[0]), cmp);
    for (i = 0; i < k;i++){
        for (j = 0; j < n;j++){
            printf("%c " ,a[i][j] + 1);
        }
        printf("\n");
    }
    return 0;
}


