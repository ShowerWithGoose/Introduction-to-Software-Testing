#include<stdio.h>
#include<string.h>
int main(){
	char c[100],s[100],m;
	int i,j=0;
	gets(c);
	i=0;
	while(c[i]!='\0'){
		s[j++]=c[i];
		if(c[i+1]=='-'&&c[i+2]>c[i]&&((c[i]>='0'&&c[i+2]<='9')||(c[i]>='A'&&c[i+2]<='Z')||(c[i]>='a'&&c[i+2]<='z'))){
			for(m=c[i]+1;m<c[i+2];m++){
				s[j++]=m;
			}
			i=i+2;
		}
		else{
			i++;
		}
	}
	s[j]='\0';
	puts(s);
	return 0;
}

