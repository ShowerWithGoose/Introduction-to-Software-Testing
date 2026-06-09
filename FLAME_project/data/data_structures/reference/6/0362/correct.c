#include<stdio.h>
#include<string.h>
struct STACK{
	int mem[100];
	int top;
}s;
typedef struct STACK stack;
int a;
void initial(stack *s){
	s->top=-1;
}
int empty(stack *s){
	return s->top==-1;
}
int full(stack *s){
	return s->top==99;
}
int pop(stack *s,int a){
	if(s->top==-1)
    {
        printf("error ");
        return 0;
    }
    else{
    	a=s->mem[s->top--];
        printf("%d ",a);
        return 1;
	}
}
int push(stack *s,int a){
	if(full(s))
    {
        printf("error ");
        return 0;
    }
    else{
    	s->mem[++s->top]=a;
        return 1;
	}
}
int main(){
	initial(&s);
	int t,i;
	while(1){
		scanf("%d",&t);
		if(t==-1)break;
		else if(t==0){
			pop(&s,a);
		}
		else if(t==1){
			scanf("%d",&i);
			push(&s,i);
		}
	}
	return 0;
}



