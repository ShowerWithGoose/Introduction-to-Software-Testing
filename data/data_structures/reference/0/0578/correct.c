#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<ctype.h>

int main(){
	char s[10000],t[10000];
	gets(s);
	t[0]=s[0];
	int i=1,j=1,m=0;
	while(s[i]!='\0'){
		if((s[i]=='-')&&(s[i+1]>s[i-1])&&((islower(s[i+1])&&islower(s[i-1]))||(isupper(s[i+1])&&isupper(s[i-1]))||(isdigit(s[i+1])&&isdigit(s[i-1])))){
			m=s[i+1]-s[i-1]-1;
			while(m--){
				t[j]=t[j-1]+1;
				j++;
			}
			i++;	
		}
		else{
			t[j++]=s[i++];
		}
	}
	t[j]='\0';
	printf("%s",t);
	return 0;
}


