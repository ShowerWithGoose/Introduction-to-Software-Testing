#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
int main(){
	char a;
	int i=0,cnt=0,flag=1;
	scanf("%c",&a);
	if(a=='0'){
		cnt--;
		scanf("%c",&a);
		scanf("%c",&a);
		while(a=='0'){
			cnt--;
			scanf("%c",&a);
		}
		printf("%c",a);
		scanf("%c",&a);
		if(a!='\n')printf(".");
		while(a!='\n'){
			printf("%c",a);
			scanf("%c",&a);
		}
	}
	else{
		printf("%c",a);
		scanf("%c",&a);
		if(a!='\n')printf(".");
		while(a!='\n'){
			if(a=='.'){
				flag--;
				scanf("%c",&a);
			}
			cnt+=flag;
			printf("%c",a);
			scanf("%c",&a);
		}
	}
	printf("e%d",cnt);
}




