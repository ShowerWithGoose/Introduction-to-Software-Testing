#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
int main(){
	char a[110];
	scanf("%s",a);
	int l=strlen(a);
	int p;
	for(int i=0;i<l;i++){
		if(a[i]=='.'){
			p=i;
			break;
		}
	}
	if(p>1||(p==1&&a[0]!='0')){
		printf("%c",a[0]);
		printf(".");
		for(int i=1;i<l;i++){
			if(i!=p)
			printf("%c",a[i]);
		}
		printf("e%d",p-1);
	}
	else{
		int s;
		for(int i=2;i<l;i++){
			if(a[i]!='0'){
			s=i;
			break;
			}
		}
		printf("%c",a[s]);
		if(s!=l-1){
		printf(".");
		for(int i=s+1;i<l;i++)
		printf("%c",a[i]);
		}
		printf("e-%d",s-1);
	}
return 0;
}




