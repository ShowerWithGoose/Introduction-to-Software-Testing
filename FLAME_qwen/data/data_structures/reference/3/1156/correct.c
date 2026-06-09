#include<stdio.h>
#include<math.h>
#include<string.h>


char a[105];
int n;
int k;
int fl=0;
int t;
int main(){
	scanf("%s",a);
	n=strlen(a);
	if(a[0]=='0'){
		for(int i=0;i<n;i++){
			if(a[i]!='.'&&a[i]!='0'){
				t=i-1;//a[t] is the last 0 or .
				break;
			}
		}
		printf("%c",a[t+1]);
		if(n-1!=t+1){
			printf(".");
			for(int i=t+2;i<n;i++){
				printf("%c",a[i]);
			}
			printf("e-%d",t);
			return 0;
		}
		else{
			for(int i=t+2;i<n;i++){
				printf("%c",a[i]);
			}
				printf("e-%d",t);
			return 0;
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]=='.'){
				t=i-1;
				fl=1;
				break;
			}
			
		}
		if(fl==0){
			n++;
			a[n]='.';
			t=n-2;
		}
		printf("%c.",a[0]);
		for(int i=1;i<t+1;i++){
			printf("%c",a[i]);
		}
		for(int i=t+2;i<n;i++){
			printf("%c",a[i]);
		}
		printf("e%d",t);
		return 0;
	}
	
	
	
	return 0;
}





