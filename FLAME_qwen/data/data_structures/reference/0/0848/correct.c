#include<stdio.h>
#include<string.h>
#include<math.h>
char in[500]={0};
int main(){
	int i,j;
	gets(in);
	for(i=0;in[i]!='\0';i++){
		if(in[i]=='-'&&in[i-1]>='a'&&in[i]-1<='z'&&in[i+1]>='a'&&in[i+1]<='z'){
			for(j=1;in[i-1]+j<in[i+1];j++){
				printf("%c",in[i-1]+j);
			}
		}
		else if(in[i]=='-'&&in[i-1]>='A'&&in[i]-1<='Z'&&in[i+1]>='A'&&in[i+1]<='Z'){
			for(j=1;in[i-1]+j<in[i+1];j++){
				printf("%c",in[i-1]+j);
			}
		}
		else if(in[i]=='-'&&in[i-1]>='0'&&in[i]-1<='9'&&in[i+1]>='0'&&in[i+1]<='9'){
			for(j=1;in[i-1]+j<in[i+1];j++){
				printf("%c",in[i-1]+j);
			}
		}
		else printf("%c",in[i]);
	}
	return 0;
}

