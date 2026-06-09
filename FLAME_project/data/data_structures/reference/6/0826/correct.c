#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
#define MAXSIZE 100
int s[MAXSIZE];
int TOP = -1;                  
void push(int s[], int item);  
void pop(int s[]);      
int main(int argc, const char * argv[]){
	while (1){
	int sign;
	scanf("%d ",&sign);
	if(sign==1){
		int in;
		scanf("%d ",&in);
		push(s,in);
	}
	if(sign==0){
	pop(s);
}
	else if(sign==-1)
	{
		break;
	}
}
return 0;
}       
void push(int s[], int in){
	if(TOP<MAXSIZE-1)
    s[++TOP]=in;
	else
	printf("error ");
}
void pop(int s[]){
	if(TOP>=0)
	printf("%d ",s[TOP--]);
	else
	printf("error ");
}


