#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAXSIZE 100

int top=-1;
int isEmpty()
{
    return top==-1;
}


int isFull(){
    return top==MAXSIZE-1;
}
void push(int s[],int j){
    if(isFull()){
        printf("error");
    }
    else
      s[++top]=j;
}

int pop(int s[]){
    if(isEmpty()){
       return 0;
    }
    else
    return s[top--];
}
int main(){
int i,j,NUM;
int STACK[MAXSIZE]={0};
while(scanf("%d",&i)!=EOF){
if(i==1){
    scanf("%d",&j);
    push(STACK,j);
}
else if (i==0)
{
NUM=pop(STACK);
    if(NUM==0)
{
   printf("error ");
}

  else{
  	
      printf("%d ",NUM);
  }
}

else if(i==-1){
    return 0;
}

}


getchar();
}

