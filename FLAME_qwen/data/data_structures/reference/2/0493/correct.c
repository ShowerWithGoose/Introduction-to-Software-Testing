#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100000
void qukong(char *s){
	int ls=strlen(s);
	int i,j;
	for(i=0,j=0;i<ls&&s[i]!='\0';i++){
		if(s[i]!=' '){
			s[j++]=s[i];
		}
	}
	s[j]='\0';
}

int isnum(char a){
	if(a>='0'&&a<='9'){
		return 1;
	}
	else  return 0;
}

int main(){
	char s[M];
	gets(s);
	qukong(s);
	int ls=strlen(s);
	int b[M],a[M];//Î»ÖÃ£¬Êý×Ö 
	int i,j=0,k=0,n=0;
	for(i=0;i<ls;i++){
		if(isnum(s[i])){
			a[k]=s[i]+10*n-'0';
			n=a[k];
		}
		else{
			b[j]=i;
			j++;
			if(s[b[j-1]]!=s[b[j-1]+1])
			k++;
			n=0;
		}
	}
	int lb=j;
	if(s[b[0]]=='='){
		printf("%d",a[0]);
		return 0;
	}
	int r=0;
	for(j=0;j<lb;j++){
		if(s[b[j]]=='-'&&s[b[j]+1]=='-'){
			a[j+1]*=-1;
			s[b[j]+1]=' ';
		}
	}
	
	for(j=0;j<lb;j++){
		if(s[b[j]]=='*'){
			r=a[j]*a[j+1];
			a[j]=a[j+1]=r;
			for(k=j;s[b[k-1]]=='*'||s[b[k-1]]=='/';k--)
			a[k-1]=r;
		}	
		else if(s[b[j]]=='/'){
			r=a[j]/a[j+1];
			a[j]=a[j+1]=r;
			for(k=j;s[b[k-1]]=='*'||s[b[k-1]]=='/';k--)
			a[k-1]=r;
		}
	}
	for(j=0;j<lb;j++){
		if(s[b[j]]=='+'){
			r=a[j]+a[j+1];
			a[j]=a[j+1]=r;
		for(k=j+1;s[b[k]]=='*'||s[b[k]]=='/';k++)
		a[k+1]=r;
		}	
		else if(s[b[j]]=='-'){
			r=a[j]-a[j+1];
			a[j]=a[j+1]=r;
			for(k=j+1;s[b[k]]=='*'||s[b[k]]=='/';k++)
		a[k+1]=r;
		
		
		}
	}
	printf("%d",r);
	return 0;
}

