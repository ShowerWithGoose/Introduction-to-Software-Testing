#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[100]; 
int top=-1;//初始化
void ru(int s[],int item);//s只是形参，可以理解成无实际意义 
void chu(int s[]); 
int main()
{
while(1){
	int flag;
scanf("%d",&flag);
if(flag==1){//1是入栈 
	int item;
scanf("%d",&item);
ru(a,item);
}else if(flag==0){//0是出栈 
	chu(a);
}else if(flag==-1){
	break;
}
}
return 0;
}
void ru(int s[],int item){
	if(top==99){//栈满 
	printf("error ");
}else{
	s[++top]=item;
}
}
void chu(int s[]){
	if(top==-1){//栈空 
	printf("error ");
}else{
	printf("%d ",s[top--]);
}
}

