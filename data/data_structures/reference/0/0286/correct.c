#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int equal(char a,char b);
int main(){
	char s[100],pr;
	int i,len,j,temp,flag=0;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++){
//		if(s[i]=='-'&&flag==1) {
//			flag=0;
//		}
//		else if(s[i]=='-'&&flag==0) printf("-");
//		else if(s[i+1]!='-'&&s[i+1]!='\0'){
//			printf("%c",s[i]);
//		}
		if(s[i+1]=='-'&&s[i+2]!='\0'&&equal(s[i],s[i+2])>1){
			temp=equal(s[i],s[i+2]);
			pr=s[i];
			for(j=0;j<temp;j++){
				printf("%c",pr++);
			}
			i++;
		}
		
		else printf("%c",s[i]);
	}
}
int equal(char a,char b){
	if(islower(a)&&islower(b)) return b-a;
	else if(isupper(a)&&isupper(b)) return b-a;
	else if(isdigit(a)&&isdigit(b)) return b-a;
	else return 0;
}


