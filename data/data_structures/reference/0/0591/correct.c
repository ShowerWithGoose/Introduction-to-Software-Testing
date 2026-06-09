#include<stdio.h>
#include<string.h>
int judge(char,char);
char c[500],s[600];
int i,j,k,d;
int main()
{
	gets(c);
	for(i=0,j=0;c[i]!='\0';i++){
		if(c[i]!='-'){
			s[j++]=c[i];
		}
		else if(judge(c[i-1],c[i+1])==0){
			s[j++]=c[i];
		}
			else{
				d=c[i+1]-c[i-1];
				for(k=0;k<d;k++){
					s[j+k]=c[i-1]+k+1;
				}
				j+=d-1;	
			}
	}
	puts(s);
	return 0;
}
int judge(char a,char b){
	if(a<b && ((a>='0'&&b<='9') || (a>='a'&&b<='z') ||(a>='A'&&b<='Z')))
		return 1;
	else return 0;
}
	
	



