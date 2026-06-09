#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
int STACK[MAXSIZE];
int Top=-1; //³õÊ¼»¯¶ÑÕ»
void push(int s[], int item)
{
    if(Top == MAXSIZE-1)//isFull() Õ»Âú
        printf("error ");
    else
        s[++Top]=item;
}

void pop(int s[])
{
      if(Top == -1)//isEmpty() ¿ÕÕ»
          printf("error ");
      else
          printf("%d ", s[Top--]);
}

int main(int argc, char *argv[]){
	int item,i,j=0,p;
	scanf("%d",&p);
	for(i=0;p!=-1;i++){
		if(p==1){
			scanf("%d",&item);
			push(STACK,item);
		}
		if(p==0){
			pop(STACK);
		}
		scanf("%d",&p);
	}
	/*for(i=0;i<100;i++)
	printf("%d ",STACK[i]);*/
	
}


