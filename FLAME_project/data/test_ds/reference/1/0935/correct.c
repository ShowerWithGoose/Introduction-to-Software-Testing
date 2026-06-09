#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	int i=0,j=1;
	char s[1000]={};
	char c[1000]={};
	gets(s);
	int n;
	n=strlen(s);
	c[0]=s[0];
	for(i=1;i<=n;i++){
		if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i]=='-'&&s[i-1]<s[i+1]){
			c[j]=s[i-1]+1;
			while(c[j]<s[i+1]-1){
				c[j+1]=c[j]+1;
				j++;
			}
			j++;
		}
		else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i]=='-'&&s[i-1]<s[i+1]){
			c[j]=s[i-1]+1;
			while(c[j]<s[i+1]-1){
				c[j+1]=c[j]+1;
				j++;
			}j++;
		}
		else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i]=='-'&&s[i-1]<s[i+1]){
			c[j]=s[i-1]+1;
			while(c[j]<s[i+1]-1){
				c[j+1]=c[j]+1;
				j++;
			}j++;
		}
		else 
		{c[j]=s[i];
		j++;
		}
	}
	
	printf("%s",c);
	return 0;
}

	 


