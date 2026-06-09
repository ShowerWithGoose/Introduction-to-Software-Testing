#include<stdio.h>
#include<ctype.h>
#include<string.h>
int kind(char c){
	if (isupper(c)) return 1;
	else if (islower(c)) return 2;
	else return 0;
}
char s[1005];
int main(){
	int i,j,k,len;
	scanf("%s",s);
	len=strlen(s);
	for (i=0;i<=len-1;){
		if (s[i]!='-'&&s[i+1]!='-'&&i<len-1){
			printf("%c",s[i++]);
		}
		else{
			if (kind(s[i])!=kind(s[i+2])||(kind(s[i])==kind(s[i+2]))&&s[i]>=s[i+2]){
				printf("%c%c%c",s[i],s[i+1],s[i+2]);
				i+=3;
			}
			else {
				if (s[i+3]!='-'){
					for (k=0,j=s[i+2]-s[i];k<=j;k++){
						printf("%c",s[i]+k);
					}
				i+=3;
					
				}
				else {
					for (k=0,j=s[i+2]-s[i];k<=j-1;k++)
					printf("%c",s[i]+k);
					i+=2;
				}
				
				j=0;
			}
			
		}
		
	}
	

	
	
	
	
	return 0;
}



