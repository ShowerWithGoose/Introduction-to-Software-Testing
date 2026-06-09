#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int Top;
int MAXSIZE=100;

//³õÊ¼»¯¶ÑÕ»
void initStack( ) {
	Top= -1;
}
//²âÊÔ¶ÑÕ»ÊÇ·ñÎª¿Õ
int	isEmpty( ) {
	return Top== -1;
}
//²âÊÔ¶ÑÕ»ÊÇ·ñÒÑÂú
int isFull(	) {
	return Top==MAXSIZE-1;
}

//½øÕ»
void push( int s[ ],int item ) {
	if( isFull() )
		Error("error");
	else
		s[++Top]=item;
}

void Error(char s[]) {
	printf("%s ", s);
}

//³öÕ»
int pop( int s[ ]) {
	if(isEmpty())
	{
		Error("error");
		return -1; 
	}
	else
		return s[Top--];
}

int main() {
	int order,temp,ans;
	//printf("\ntop=%d\n",Top);
	//initStack;
	Top=-1;
	//printf("\ntop=%d\n",Top);
	int s[100];

	while(scanf("%d",&order)) {
		if(order==1) {
			scanf("%d",&temp);
			push(s,	temp );
			//printf("\ntop=%d\n",Top);
		}
		if(order==0) {
			ans=pop( s );
			if (ans!=-1) printf("%d ",ans);
			//printf("\ntop=%d\n",Top);
		}
		if(order==-1)
		break;
	}
	
	return 0;
}

