#include <stdio.h>
int push(int a[], int j){
	int news;
	scanf("%d ", &news);
	if(j > 99){
		printf("error ");
	}
	else{
		a[j + 1] = news;
	}
	return j + 1;
}
int pull(int a[], int j){
	if(j - 1 < 0){
		printf("error ");
	}
	else{
		printf("%d ", a[j]);
	}
	return j - 1;
}
int main(){
	int sig;
	int stack[99];
	int i = 0;
	while (scanf("%d", &sig)){
		if (sig == -1) break;
		if (sig == 1){
			i = push(stack, i);
		}
		else{
			i = pull(stack, i);
		}
	}
	return 0;
}

