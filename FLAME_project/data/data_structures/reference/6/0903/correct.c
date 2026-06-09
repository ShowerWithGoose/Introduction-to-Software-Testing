#include<stdio.h>
int main(){
	int stack[105]={0},act=0,num=0,i=0;
	while (scanf("%d", &act) != EOF) {
		if (act==-1){
			return 0;
		}else if (act==0){
			if (i==0){
				printf ("error ");
			}else if(i>=1){
				printf ("%d ",stack[i]);
				stack[i]=0;
				i--;
			}
		}else if (act==1) {
			scanf("%d", &num);
			stack[++i]=num;
		}	
	}
	printf (" ");
	return 0;
}
/*
#include<stdio.h>
#define MAXSIZE 105
int  STACK[MAXSIZE];
int Top=-1;
int isEmpty( )
{
    return Top== -1;
} 
int isFull(  )
{
    return Top==MAXSIZE-1;
}
void  push(int s[ ],int item )
{
    if( isFull() ) {
    	
	}
        Error("Full Stack!");
    else
    	s[++Top]=item; 
}
int pop(int s[ ])
{
    if(isEmpty())
        Error("Empty Stack!");
    else
    	return s[Top--]; 
}*/






