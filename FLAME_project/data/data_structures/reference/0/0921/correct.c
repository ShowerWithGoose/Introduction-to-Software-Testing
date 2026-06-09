#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	char s[100],t[100];
	int i,j,k,q;
	gets(s);
	for(i=0,j=0;s[i]!='\0';i++){
		if(s[i]!='-'){
			t[j++]=s[i];
		}
		else{
			if(islower(s[i-1])*islower(s[i+1])!=0||isupper(s[i-1])*isupper(s[i+1])!=0||isdigit(s[i-1])*isdigit(s[i+1])!=0){
				for(k=1;s[i+1]-s[i-1]-k>0;k++){
					t[j++]=s[i-1]+k;
				}
			}
			else{
				t[j++]=s[i];
			}
		}
	}
	for(q=0;q<j;q++){
		printf("%c",t[q]);
	}
	return 0;
}




