#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
#define max 200
struct shu
{
	int shuzi[200];
	int top;
}s;
typedef struct shu stack;
int push(stack *s,int e)
{
	s->shuzi[++s->top]=e;
	return 1;
}
void initstack(stack *s){
	s->top=-1;
}
int pop(struct shu *s)
{
	if(s->top==-1)
	{
		printf("error ");
		return 0;
	}
	//*e=s->shuzi[s->top];
	printf("%d ",s->shuzi[s->top]);
	s->top--;
	return 1;
}
int main()
{
	/*FILE *fp1;//定义文件指针 
	fp1 = fopen("filein.txt","r");//r为读 
	FILE *fp2; //定义文件指针 
	fp2 = fopen("fileout.txt","w");//w为写 
	fclose(fp1);
	fclose(fp2);*/
	initstack(&s);
	int a,b;
	while(~scanf("%d ",&a)!=0)
	{
		if(a==1)
		{
			scanf("%d ",&b);
			push((void *)&s,b);
		}
		if(a==0)
		{
			pop((void *)&s);
		}
		if(a==-1)
		{
			return 0;
		}
	}
	return 0;	
 }




