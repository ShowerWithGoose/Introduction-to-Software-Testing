#include<stdio.h>
#include<string.h>
#define MAX 125
int STACK[MAX];
int top,temp;
int a,b,q;
int emptys(int top){
    return (top==-1);
}
int fulls(int top){
    return (top==MAX-1);
}
int getstop(int STACK[],int *top,int *temp){
    if(emptys(*top))return 0;
    else{
        *temp=STACK[(*top)--];
        return 1;
    }
}
int push(int STACK[],int *top,int item){
    if(fulls(*top))return 0;
    else{
        STACK[++*top]=item;
        return 1;
    }
}
int main(){
	top=-1;
    while(scanf("%d",&a)){
        if(a==1){
        	scanf("%d",&b);
        	if(push(STACK,&top,b)==0)printf("error ");
        }
        else if(a==0){
        	if(getstop(STACK,&top,&q)==0)printf("error ");
        	else printf("%d ",q);
        }
        if(a==-1)return 0;
	}
    return 0;
}

