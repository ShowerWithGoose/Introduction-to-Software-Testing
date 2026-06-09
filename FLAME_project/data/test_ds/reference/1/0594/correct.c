#include<stdio.h>
#include<string.h>
#define MAXN 1024
char in[MAXN],out[MAXN];
int i,j,k,len,op;
int main(){
	gets(in);
	len=strlen(in);
	for(i=0,j=0;i<=len-2;i++,j++,op=0){
		if(in[i]=='-'){
			if(in[i-1]<='9'&&in[i-1]>='0'){
				if(in[i+1]>='0'&&in[i+1]<='9'&&in[i+1]>in[i-1]){
					op=1;
					for(k=1,j--;k<in[i+1]-in[i-1];k++){
						j++;
						out[j]=in[i-1]+k;
					}
				}
			}else if(in[i-1]<='z'&&in[i-1]>='a'){
				if(in[i+1]>='a'&&in[i+1]<='z'&&in[i+1]>in[i-1]){
					op=1;
					for(k=1,j--;k<in[i+1]-in[i-1];k++){
						j++;
						out[j]=in[i-1]+k;
					}
				}
			}else if(in[i-1]<='Z'&&in[i-1]>='A'){
				if(in[i+1]>='A'&&in[i+1]<='Z'&&in[i+1]>in[i-1]){
					op=1;
					for(k=1,j--;k<in[i+1]-in[i-1];k++){
						j++;
						out[j]=in[i-1]+k;
					}
				}
			}
			if(op==0)out[j]='-';
		}else{
			out[j]=in[i];
		}
	}
	out[j]=in[len-1];
	for(i=0;i<=j;i++)printf("%c",out[i]);
	return 0;
}
