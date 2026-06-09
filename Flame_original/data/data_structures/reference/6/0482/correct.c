#include<stdio.h>
#include<string.h>

int hia[101]; 
int cnt = 0;

int main()
{
	int c = 0;
	while(c != -1){
		scanf("%d",&c);
		if(c == 0){
			if(cnt == 0 || cnt == 100)
				printf("error ");
			else
				printf("%d ",hia[cnt--]);
		}
		else if(c == 1){
			cnt += 1;
			scanf("%d",&c);
			hia[cnt] = c;
		}
	}
}
 

