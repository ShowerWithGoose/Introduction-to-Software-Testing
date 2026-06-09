#include<stdio.h>
#include<string.h>
int js(int a,char b,int c)//¶şÔª¼ÆËã 
{
	if(b=='+')	return a+c;
	else if(b=='-')	return a-c;
	else if(b=='*')	return a*c;
	else if(b=='/')	return a/c;
}
int pd(char a,char b)
{
	if((a=='+'||a=='-')&&(b=='+'||b=='-'))	return 1;
	else if((a=='+'||a=='-')&&(b=='*'||b=='/'))	return 2;
	else if((a=='*'||a=='/')&&(b=='+'||b=='-'))	return 3;
	else if((a=='*'||a=='/')&&(b=='*'||b=='/'))	return 4;
}
//5+2*3*3=
int main(){
	
	int a,b,c;
	char head,tail;
	
	scanf(" %d %c",&a,&head);
	if(head=='=')	{printf("%d",a);	}
	//scanf("%d %c %d",&b,&tail,&c);
	else{
		scanf(" %d %c",&b,&tail);
		if (tail=='=')printf(" %d",js(a,head,b));
		else{
			scanf(" %d",&c);
			while(tail!='='){
//				printf("*");
				if(pd(head,tail)!=2)
				{
					a=js(a,head,b);
					head=tail;
					b=c;
					scanf(" %c",&tail);
					if(tail!='=')	scanf(" %d",&c);
						}
				else
				{
					b=js(b,tail,c);
					scanf(" %c",&tail);
					if(tail!='=')	scanf(" %d",&c);
						}		
				

			}
			printf("%d ",js(a,head,b));
		}
	//				if(head=='='){
//					printf("%d",a);
//					printf("#");
//					break;
//				}
//				else if(tail=='='){
//					printf("%d",js(a,head,b));
//					printf("!");
//					break;
//				}	
//	scanf(" %d ",&c);
	
		//printf("%d %c %d % c%d",a,head,b,tail,c);
		return 0;
	}
	
} 



