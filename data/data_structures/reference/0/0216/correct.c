#include<stdio.h>
#include<string.h>
char s[1000000],p[1000000]; 
int main (){
    gets(s);int i,j=0;
    for(;s[i]!='\0';i++){
    	if(s[i]=='-'&&i!=0&&s[i-1]+1<s[i+1]){
    		if(s[i-1]>='0'&&s[i+1]<='9'||s[i-1]>='a'&&s[i+1]<='z'||s[i-1]>='A'&&s[i+1]<='Z')
    		for(p[j]=s[i-1]+1;p[j]<s[i+1]-1;j++) p[j+1]=p[j]+1;
    		else p[j]=s[i];
		}
		else p[j]=s[i];
		j++;
	}
	p[j]='\0';
	printf("%s",p);
	}


