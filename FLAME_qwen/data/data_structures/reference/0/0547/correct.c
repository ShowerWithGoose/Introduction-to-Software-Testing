#include<stdio.h>
#include<string.h>
char a[5000],b[10000];
int i=0,j=0;

int panduan(int len){
	if((i==0)||(i==len-1)) return 0;
	if((a[i-1]>='a')&&(a[i-1]<='z')){
		if((a[i+1]>='a')&&(a[i+1]<='z')&&(a[i-1]<a[i+1])) return 1;
		else return 0;
	}
	if((a[i-1]>='A')&&(a[i-1]<='Z')){
		if((a[i+1]>='A')&&(a[i+1]<='Z')&&(a[i-1]<a[i+1])) return 1;
		else return 0;
	}
	if((a[i-1]>='0')&&(a[i-1]<='9')){
		if((a[i+1]>='0')&&(a[i+1]<='9')&&(a[i-1]<a[i+1])) return 1;
		else return 0;
	}
}

void kuozhan(){
	for(char x=a[i-1]+1;x<a[i+1];x++){
		b[j++]=x;
	}
	i++;
}

int main() {
	gets(a);
	int len=strlen(a);
	while(i<len){
		if(a[i]!='-') b[j++]=a[i++];
		else{
			if(panduan(len)!=0) kuozhan();
			else{
				b[j++]=a[i++];
			}
		}
	}
	puts(b);
	return 0;
}



