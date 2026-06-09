#include<stdio.h>
#include<string.h>

char s[1001],c[10001];
int flag=0,t=0,i=0,j=0;
 
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(i=0;i<n;++i){
		if(s[i]!='-') c[j++]=s[i];
		else{
			flag=0;
			t=0;
			if((s[i-1]<='z'&&s[i-1]>='a')&&(s[i+1]<='z'&&s[i+1]>='a')&&(s[i+1]>s[i-1])){
				t=s[i+1]-s[i-1]-1;
				for(int k=1;k<=t;++k){
					c[j++]=s[i-1]+k;
				}
				flag=1;
			}
			else if((s[i-1]<='Z'&&s[i-1]>='A')&&(s[i+1]<='Z'&&s[i+1]>='A')&&(s[i+1]>s[i-1])){
				t=s[i+1]-s[i-1]-1;
				for(int k=1;k<=t;++k){
					c[j++]=s[i-1]+k;
				}
				flag=1;
			}
			else if((s[i-1]<='9'&&s[i-1]>='0')&&(s[i+1]<='9'&&s[i+1]>='0')&&(s[i+1]>s[i-1])){
				t=s[i+1]-s[i-1]-1;
				for(int k=1;k<=t;++k){
					c[j++]=s[i-1]+k;
				}
				flag=1;
			}
			if(flag==0) c[j++]=s[i];
		}
	}
	printf("%s",c);
	return 0;
}



