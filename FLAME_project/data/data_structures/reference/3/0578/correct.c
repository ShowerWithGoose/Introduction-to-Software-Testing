#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(){
	char s[105],t[105];
	gets(s);
	if(s[0]=='0'){
		int k=2,i=2;
		while(s[k]=='0'){
			k++;
		}
		if(s[k+1]!='\0'){
			t[0]=s[k];
			t[1]='.';
			while(i+k-1<=strlen(s)){
				t[i]=s[i+k-1];
				i++;
			}
		}
		else{
			t[0]=s[k];
			t[1]='\0';
		}
		printf("%se-%d",t,k-1);
	}
	else{
		int k=0,i=2;
		while(s[k]!='.'){
			k++;
		}
		t[0]=s[0],t[1]='.';
		while(i<=k){
			t[i]=s[i-1];
			i++;			
		}
		while(i<=strlen(s)){
			t[i]=s[i];
			i++;
		}
		printf("%se%d",t,k-1);
}
	return 0;	
}

