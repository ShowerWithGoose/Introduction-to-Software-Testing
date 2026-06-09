#include <stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top = -1;  
int main(){
	int n,a;
	while(1){
		scanf("%d",&n);
		if(n==1){
			scanf("%d",&a);
			push(STACK,a);
		}
		else if(n==0){
			pop(STACK);
		}
		else  return 0;
	}
	return 0;
}
void push(int s[], int item)
{
    if(Top == MAXSIZE-1)
        printf("error ");
    else
        s[++Top]=item;
}

void pop(int s[])
{
      if(Top == -1)
          printf("error ");
      else
          printf("%d ", s[Top--]);
}

