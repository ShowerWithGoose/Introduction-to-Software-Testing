#include<stdio.h>
#include<string.h>

int n;
/*int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void swap(int i, int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
method 1
void permutation(){
	while(1){
		int i, j, k;
		for(i = 0; i < n; i++){
			printf("%s%d", i == 0 ? "" : " ", a[i]);
		}
		puts("");
		for(j = n - 2; j >= 0 && a[j] > a[j + 1]; j--);
		if(j < 0) return;
		for(k = n - 1; k > j && a[k] < a[j]; k--);
		swap(j, k);
		int l, r;
		for(l = j + 1, r = n - 1; l < r; l++, r--){
			swap(l, r);
		}
	}
}*/
//method 2
int vis[11], arr[11];
void dfs(int position){
	int i; 
	if(position == n + 1){
		for(i = 1; i <= n; i++){
			printf("%s%d", i == 1 ? "" : " ", arr[i]);
		}
		puts("");
		return;
	}
	for(i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		arr[position] = i;
		dfs(position + 1);
		vis[i] = 0;
	}
}
/*void permutation1(int a[], int first, int last){
	if(first == last){
		int i;
		for(i = 0; i < n; i++){
			printf("%s%d", i == 0 ? "" : " ", a[i]);
		}
		puts("");
	}else{
		int i;
		for(i = first; i <= last; i++){
			swap(a, first, i);
			permutation1(a, first + 1, last);
			swap(a, first, i);
		}
	}
}*/
int main(){
	scanf("%d", &n);
	dfs(1);
	return 0;
} 

