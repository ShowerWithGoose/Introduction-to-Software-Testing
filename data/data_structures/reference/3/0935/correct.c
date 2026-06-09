#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
		char s[1000]={};
		char c[1000]={};
		int i=0,j=0,flag=0,elk=0,e=0;
		gets(s);
		j=strlen(s);
		for(i=0;i<j;i++){
			if(s[i]=='.')
			{flag=1;elk=i;
			}
		}
		if(flag==1){
			if(s[0]!='0'){
			
			for(i=0;i<j;i++){
				if(s[i]>='0'&&s[i]<='9'){
					c[e]=s[i];
					e++;
				}
			}
			for(i=0;i<e;i++){
				printf("%c",c[i]);
				if(e!=1){if(i==0){
					printf(".");
				}
				}
				
			}
			printf("e%d",elk-1);}
			else{i=2;
				int sum=0;
				while(s[i]=='0'){
					sum++;
					i++;
				}
				for(i=sum+2;i<j;i++){
				if(s[i]>='0'&&s[i]<='9'){
					c[e]=s[i];
					e++;
				}
			}
			for(i=0;i<e;i++){
				printf("%c",c[i]);
				if(e!=1){if(i==0){
					printf(".");
				}
				}
				
			}
			printf("e%d",-sum-1);
				
			}
		}
		else {for(i=0;i<j;i++){
				if(s[i]>='0'&&s[i]<='9'){
					c[e]=s[i];
					e++;
				}
			}
			for(i=0;i<e;i++){
				printf("%c",c[i]);
				if(e!=1){if(i==0){
					printf(".");
				}
				}
				
			}
			printf("e%d",j-1);
			
		}
	return 0;
}

