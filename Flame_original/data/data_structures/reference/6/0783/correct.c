#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
typedef int ElemType;
int Top;
void initStack();
int isEmpty();
int isFull();
ElemType pop(ElemType s[]);
int main(){
	int flag=0,i=0,cnt=0,n;
	ElemType s[MAX];
	initStack();
	while(flag!=-1){
		scanf("%d",&flag);
		if(flag==1){
			scanf("%d",&n);
			if(!isFull()){
				s[++Top]=n;
				cnt++;
			}
			else if(isFull()){
				printf("error ");
			}
		}
		else if(flag==0&&!isEmpty()){
			pop(s);
			printf("%d ",s[Top+1]);
			cnt--;
		}
		else if(flag==0&&isEmpty()){
			printf("error ");
		}
		else if(flag==-1){
			break;
		}
	}
	return 0;
}
void initStack(){
	Top=-1;
}
int isEmpty(){
	return Top==-1;
}
int isFull(){
	return Top==MAX-1;
}
ElemType pop(ElemType s[]){
	return s[Top--];
}

