#include<stdio.h>
#include<string.h>
char s[200],a[200];
int main(){
	gets(s);
	int count=0;
	for(int i=0,j=0;i<=strlen(s);i++){
		if(s[i]=='.') count=i;
		else if(s[i]>='0'&&s[i]<='9')a[j++]=s[i];
	}
	if(a[0]=='0'){
		int start=0,end=-1;
		/*Find the start of the array except for "0"*/
		for(int i=0;i<strlen(a);i++){
			if(a[i]=='0') continue;
			else{
				start=i;break;
			}
		}
		/*Find the end of the array */
		for(int i=strlen(a)-1;i>=start;i++){
			if(a[i]=='0') continue;
			else{
				end=i;break;
			}
		}
		printf("%c",a[start]);
		if(start==end) printf("e-%d",start);
		else{
			printf(".");
			for(int i=start+1;i<=end;i++) printf("%c",a[i]);
			printf("e-%d",start);
		}
	}
	else{
		printf("%c",a[0]);
		int end=-1,m=strlen(a)-1;
		for(int i=m;i>=count;i--){
			if(a[i]=='0') continue;
			else{
				end=i;break;
			}
		}
		if(end==-1){
			for(int i=1;i<count;i++) printf("%c",a[i]);
		}
		else {
			printf(".");
			for(int i=1;i<=end;i++) printf("%c",a[i]);
			printf("e%d",count-1);
		}
	}
} 

