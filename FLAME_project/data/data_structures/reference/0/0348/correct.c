#include <stdio.h>
#include <string.h>
int main(){
	char s[100],c[1000];
	int i,j;
	scanf("%s",s);
	for(i=0,j=0;s[i]!='\0';i++,j++){
		if(s[i]=='-'){
			if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')&&(s[i-1]<s[i+1])){
				int a=s[i+1]-s[i-1];
				c[j+a-1]=s[i+1];
				for(a=1;a<s[i+1]-s[i-1];a++){
					c[j+a-1]=s[i-1]+a;
				}
				i++;
				j=j+a-1;		
			}
			else if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')&&(s[i-1]<s[i+1])){
				int a=s[i+1]-s[i-1];
				c[j+a-1]=s[i+1];
				for(a=1;a<s[i+1]-s[i-1];a++){
					c[j+a-1]=s[i-1]+a;
				}
				i++;
				j=j+a-1;		
			}
			else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')&&(s[i-1]<s[i+1])){
				int a=s[i+1]-s[i-1];
				c[j+a-1]=s[i+1];
				for(a=1;a<s[i+1]-s[i-1];a++){
					c[j+a-1]=s[i-1]+a;
				}
				i++;
				j=j+a-1;		
			}
			else{
				c[j]=s[i];
			}
		}
		else{
			c[j]=s[i];
		}
	}
	printf("%s\n",c);
	return 0;
}

