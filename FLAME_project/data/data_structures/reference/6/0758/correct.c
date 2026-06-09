#include <stdio.h>
#include <stdlib.h>

struct stack{
	int data[101];
	int top;
};
struct stack s;

int main() {
	int i,j;
	s.top = 0;
	while(scanf("%d",&i) != EOF){
		if(i == 1){
			scanf("%d",&j);
			if(s.top >= 100)
				printf("error ");
			else{
				s.data[s.top] = j;
				s.top ++;
			}
		}
		else if(i == 0){
			if(s.top <= 0)
				printf("error ");
			else{
				s.top --;
				printf("%d ",s.data[s.top]);
			}
		}
		else if(i == -1)
			break;
	}
	return 0;
}

