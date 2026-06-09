#include<stdio.h>
#include<string.h>
int main(){
	char s[10000]={},t[10000]={};
	scanf("%s",s);
	int i,j;
	int len=strlen(s);
	for(i=0,j=0;i<len;i++){
		if(i==0||s[i]!='-')
			t[j++]=s[i];
		else{
			if((s[i-1]>='a'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'&&s[i+1]>s[i-1])\
			||(s[i-1]>='A'&&s[i+1]>='A'&&s[i-1]<='Z'&&s[i+1]<='Z'&&s[i+1]>s[i-1])\
			||(s[i-1]>='0'&&s[i+1]>='0'&&s[i-1]<='9'&&s[i+1]<='9'&&s[i+1]>s[i-1]))
				for(char tmp=s[i-1]+1;tmp<s[i+1];tmp++)
					t[j++]=tmp;
			else
				t[j++]=s[i];
		}
	}
	puts(t);
	return 0;
}




