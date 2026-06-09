#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int judge(char*);
int main(){
	const char ch='-';
	char s[10000],t[10000];
	char *p;
	int i,j,m,ob,ob2=0;
	scanf("%s",s);
	if(strchr(s,ch)==NULL){
		ob=0;
	}
	else{
	p=strchr(s,ch);
	ob=judge(p);}
	while(ob==1){
		strcpy(t,p+2);//зЂвтЪЧ+2
		for(i=*(p-1),j=*(p+1),m=0;i<j;i++,m++){
		
			*(p+m)=*(p-1)+m+1;
		
		}
		*(p+m)='\0';
		strcat((p),t);
		if(strchr(s,ch)==NULL){
		ob=0;
		}
		else{
		p=strchr(s,ch);
		ob=judge(p);}
	
	}
	if(ob2==1) *(p+1)='\0';
	printf("%s",s);
	return 0; 
} 
int judge (char *p){
	if (islower(*(p-1))&&islower(*(p+1))&&(*(p-1)<*(p+1))){
		return 1;
	}
	else if(isupper(*(p-1))&&isupper(*(p+1))&&(*(p-1)<*(p+1))){
		return 1;
	}
	else if(isdigit(*(p-1))&&isdigit(*(p+1))&&(*(p-1)<*(p+1))){
		return 1;
	}
	else return 0;
}



