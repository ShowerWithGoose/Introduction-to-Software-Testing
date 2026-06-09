#include<stdio.h>
#include<string.h>
int main(){
	char s[1000]={'0'},b[1000]={'0'};
	gets(s);
	int q,k=0;
	q=strlen(s);
	for(int i=0;i<q;i++){
		if(s[i]!='-')
		b[k++]=s[i];
		else{
			 if(s[i+1]-s[i-1]>0&&s[i-1]>='a'&&s[i+1]<='z')
			for(int j=0;j<s[i+1]-s[i-1]-1;j++){
				b[k++]=s[i-1]+j+1;
				
			}
			else if(s[i+1]-s[i-1]>0&&s[i-1]>='A'&&s[i+1]<='Z')
			for(int j=0;j<s[i+1]-s[i-1]-1;j++){
				b[k++]=s[i-1]+j+1;
				
			}
				else if(s[i+1]-s[i-1]>0&&s[i-1]>='0'&&s[i+1]<='9')
			for(int j=0;j<s[i+1]-s[i-1]-1;j++){
				b[k++]=s[i-1]+j+1;
				
			}
			else 
			b[k++]=s[i];
		}
		
	}
	for(int i=0;i<k;i++){
		printf("%c",b[i]);
	}
	return 0;
}

