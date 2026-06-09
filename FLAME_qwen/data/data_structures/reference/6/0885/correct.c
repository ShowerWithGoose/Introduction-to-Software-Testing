#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
int s[110],num,op,in;
void push(int a)
{
	if(num==100)
	printf("error");
	else s[++num]=a;
}
int pop()
{
	if(num==0)
	printf("error ");
	else {
		printf("%d ",s[num]);
		s[num]=0;
		num--;
	}
}
int main()
{
 	//FILE *IN,*OUT;
 	//IN=fopen("","r");
 	//OUT=fopen("","w");
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i;
	while(1)
	{
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&in);
			push(in);
		}
		else if(op==0){
			pop();
		}
		else {
			break;
		}
	}
	//fclose(IN);
	//fclose(OUT);
	return 0;
}


