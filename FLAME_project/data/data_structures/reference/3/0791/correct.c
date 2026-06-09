#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define LL long long
#define ULL unsigned long long 
char ch[999999];
int main() {
    int i,num1,num2,flag=0;
    scanf("%s",ch);
    for(i=0;i<=strlen(ch)-1;i++){
    	if(ch[i]<='9'&&ch[i]>='1'){
    		num1=i;
    		break;
		}
	}
	for(i=0;i<=strlen(ch)-1;i++){
		if(ch[i]=='.'){
			num2=i;
			break;
		}
	}
	for(i=0;i<=strlen(ch)-1;i++){
		if(ch[i]<='9'&&ch[i]>='1'){
			flag++;
		}
	}
	printf("%c",ch[num1]);
	if(flag>1){
		printf(".");
	}
	for(i=num1+1;i<=strlen(ch)-1;i++){
		if(ch[i]!='.')
		printf("%c",ch[i]);
	}
	printf("e");
	if(num2-num1>=1){
		num2--;
	}
	printf("%d",num2-num1);
	return 0;
}

