#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 100

int main(){
	int flag,num,top = 0,a[MAX];
	while (scanf("%d",&flag),flag != -1){
		if (flag == 1){
			if (top == MAX)
				printf("error ");
			else {
				scanf("%d",&num);
				a[top++] = num;
			} 
		}	
		else {
			if (top == 0)
				printf("error ");
			else 
				printf("%d ",a[--top]);
		}
	}
	return 0;
} 

