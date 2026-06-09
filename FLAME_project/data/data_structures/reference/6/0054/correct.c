#include<stdio.h>
#define MAXSIZE 100
int Top=-1;
int s[MAXSIZE];
int main(){
	int x;
	while(1){
		scanf("%d",&x);
		if(x==1)
		{
			int y;
			scanf("%d",&y);
			if(Top == MAXSIZE-1)
        		printf("error ");
    		else
        		s[++Top]=y;
		}
		else if(x==0)
		{
			if(Top == -1)
          		printf("error ");
      		else
          		printf("%d ", s[Top--]);
		}
		else if(x==-1)
		break;
	}
} 

