#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void push(int [], int, int);
void pop(int [], int);
int full(int);
int empty(int);

int main(){
	int a, b, top=-1;
	int s[100];
	while(scanf("%d", &a)){
		if(a == -1){
			break;
			} 
		
		else if(a == 1){
			scanf("%d", &b);
			if(full(top)){
				printf("error ");
			}
			else{
			push(s, b, top);
			top++;
			}
		}
		
		else if(a == 0){
			if(empty(top)){
				printf("error ");
			}
			else{
				pop(s, top);
				top--;
			}
		}
	}
}

void push(int s[], int x, int top){
	s[++top] = x;
}

int full(int top){
	return top==99;
}

void pop(int s[], int top){
	printf("%d ", s[top--]);
}

int empty(int top){
	return top==-1;
}

