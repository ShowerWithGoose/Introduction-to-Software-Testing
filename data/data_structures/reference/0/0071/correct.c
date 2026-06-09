#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
int main(){
	char s[100];
	gets(s);
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]=='-'){
			if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
				int d=s[i+1]-s[i-1];
				for(int j=1;j<d;j++){
					printf("%c",s[i-1]+j);
				}

			}
			else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
				int d=s[i+1]-s[i-1];
				for(int j=1;j<d;j++){
					printf("%c",s[i-1]+j);
				}

			}
			else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
				int d=s[i+1]-s[i-1];
				for(int j=1;j<d;j++){
					printf("%c",s[i-1]+j);
				}

			}
			else{
				printf("-");
			}
		}
		else{
			printf("%c",s[i]);
		}
	} 




}




