#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int STACK[100];
int top=-1;
int isEmpty();
int isFull(); 
void  Error(char s[]);
void  push( int s[ ],int item);
void pop( int s[ ]);
int main()
{
	int a,b;
	while(scanf("%d",&a)!='/0')
	{
		if(a==-1)
		break;
		if(a==1)
		{
			scanf("%d",&b);
			push(STACK,b); 
		 } 
		 if(a==0)
		 {
		 	pop(STACK);
		 }
		 
	}
	return 0;
 } 
 //≥ı ºªØ’ª 
 //≈–∂œ’ªø’ ’ªø’∑µªÿ1 ∑Ò‘Ú∑µªÿ0 
 //≈–∂œ’ª¬˙
 void  Error(char s[])
{
        printf("%s ", s);
}
void  push( int s[ ],  int item ){
        if( isFull() )
        Error("error");
        else
		s[++top]=item;  //»Î’ª≥…π¶ 
}
void pop( int s[ ])
{
      if(isEmpty())
      {
    Error("error");
	}
      else
     printf("%d ",s[top--]);
}
int isFull( )
{
      return top==99;
}
int  isEmpty( )
{
       return top==-1;
} 




  

