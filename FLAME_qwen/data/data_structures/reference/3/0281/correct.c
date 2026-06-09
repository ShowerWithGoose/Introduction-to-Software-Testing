#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int num;
	char a[200];
	gets(a);
	int max=strlen(a);
	int i=0;
	int j;
	int temp2;
	int k,m;	
		while(i<max&&a[i]!='.'){
			i++;
		}
		int temp=i;
		if(a[1]=='.'&&a[0]=='0'){
			for(j=2;j<max;j++){
				if(a[j]=='0') continue;//数一下0的个数，0的个数其实对应了10的负多少次方 
				else break;
			}
			temp2=j;
			if(temp2!=max-2&&max>3){
				printf("%d.",a[j]-'0');
				for(;j+1<max;j++){
				printf("%d",a[j+1]-'0');
			}
			}
			else{
			for(;j<max;j++){
				printf("%d",a[j]-'0');
			}
		}
			printf("e-%d",temp2-1);
	}
		else if(temp==max-1){
				printf("%d.",a[0]-'0');
			for(m=1;m<max;m++){
				printf("%d",a[m]-'0');
			}
			printf("e%d",temp-1);
		}
		
		
		else{
			printf("%d.",a[0]-'0');
			for(k=1;k<max;k++){
				if(a[k]=='.');
				else printf("%d",a[k]-'0');
			}
			printf("e%d",temp-1);
		}
		return 0; 
	}

