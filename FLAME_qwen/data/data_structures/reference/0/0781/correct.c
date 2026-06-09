#include<stdio.h>
#include<math.h>
#include<string.h>
char ch1[300],ch2[300];
int main(){
	gets(ch1);
	int i,j;
	for(i=j=0;ch1[i]!='\0';i++){
		if(ch1[i]!='-'){
			ch2[j++]=ch1[i];
		}
		else if(ch1[i-1]>='a'&&ch1[i+1]<='z'&&ch1[i-1]<ch1[i+1]){
			while(ch2[j-1]<ch1[i+1]-1){
				ch2[j]=ch2[j-1]+1;j++;
			}
		}
		else if(ch1[i-1]>='A'&&ch1[i+1]<='Z'&&ch1[i-1]<ch1[i+1]){
			while(ch2[j-1]<ch1[i+1]-1){
				ch2[j]=ch2[j-1]+1;j++;
			}
		}
		else if(ch1[i-1]>='0'&&ch1[i+1]<='9'&&ch1[i-1]<ch1[i+1]){
			while(ch2[j-1]<ch1[i+1]-1){
				ch2[j]=ch2[j-1]+1;j++;
			}
		}
		else{
			ch2[j++]='-';
		}
	}
	puts(ch2);
}

