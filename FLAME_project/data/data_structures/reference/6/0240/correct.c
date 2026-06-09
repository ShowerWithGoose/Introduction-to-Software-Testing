#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>

#define MAXSIZE 100
/*
typedef int Datatype;//结构体――动态数组array，空间容量capacity，元素个数top 
typedef struct StackD{
	Datatype* array;
	int capacity;
	int top;
}StackD;

void StackDinit(StackD* s,int capa){//初始化 
	assert(s);//参数检测
	s->array=(Datatype*)malloc(sizeof(Datatype)* capa);//申请空间 
	if(NULL == s->array){
		assert(0);
		return;
	}
	s->capacity=capa;
	s->top=0;
} 

int StackDempty(StackD* s){//检测栈是否为空 
	assert(s);
	if(0==s->top)return 1;
	else return 0;
}

void StackDpush(StackD* s,Datatype data){//入栈 
	assert(s);
	if(s->top<s->capacity){
		s->array[s->top]=data;
		s->top++;
	}
	else{
		int capa=2*s->capacity;
		s->array=(Datatype*)realloc(s->array, sizeof(Datatype)*capa);
		s->capacity=capa;
		s->array[s->top]=data;
		s->top++;
	}
}

void StachDpop(StackD* s){//出栈 
	assert(s);
	if(StackDempty(s)){
		printf("栈已空，无法出栈！！\n");
		return;
	}
	else
	s->top--;
} 

int main(){
	StackD* stk;
	StackDinit(stk,100);
	int j,i=0;
	do{
		scanf("%d",&stk->array[i++]);
	}while(stk->array[i]!=-1);
	int n=0,op=i;
	for(j=0;j<op;j++){
		switch(stk->array[j]){
			case 1:StackDpush(stk,stk->array[j+1]);n++;break;
			case 0:StachDpop(stk);n--;break;
			case -1:break;
		}
	}
	for(j=0;j<n;j++){
		printf("%d",stk->array[j]);
	}
	return 0;
}
*/
/*
typedef int elemtype;
#define Maxsize 100
elemtype stack[Maxsize];
int top=-1; 
*/
struct Stack{
	int item[5000];
	int data;
};
/*
void initstack()
{
	top=-1;
}

int is_empty()
{
	return top==-1;
}

int is_full()
{
	return top==Maxsize-1;
}

void error(const char s[]){
	printf("%s\n",s);
	exit(-1);
}

void push(elemtype s[],elemtype item)
{
	if(is_full())
	  error("Full Stack!");
	else
	  s[++top]=item;
}

elemtype pop(elemtype s[])
{
	if(is_empty())
	  error("Empty Stack!");
	else
	  return s[top--];
}
*/
struct Stack s;

int main()
{
	int i=0,ans=0;
	do{
		scanf("%d",&s.data);
		switch(s.data){
			case 1:scanf("%d",&s.data);s.item[i]=s.data;ans++;i++;break;
			case 0:{
				if(ans==0)printf("error ");
			    else {
			    	printf("%d ",s.item[ans-1]);ans--;i--;
				}
				break;
			}
		}
	}while(s.data!=-1);
	return 0;
}




