#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char s1[10000],s2[10000];

int main()
{
	gets(s1);
	int i,j;
	for(i=0,j=0;i<strlen(s1);i++){
		if(s1[i]!='-')
			s2[j++]=s1[i];
		else if(s1[i+1]>s1[i-1]&&((islower(s1[i+1])&&islower(s1[i-1]))||(isupper(s1[i-1])&&isupper(s1[i+1]))||(isdigit(s1[i-1])&&isdigit(s1[i+1])))){
			while(s2[j-1]<s1[i+1]-1){
				char c=s2[j-1]+1;
				s2[j++]=c;
			}	
		} 
		else s2[j++]=s1[i];   
	}
	printf("%s",s2);
	return 0;
}


