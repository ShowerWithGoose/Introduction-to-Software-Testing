#include<stdio.h>
#include<string.h>
int x[100]={0};
int main(){
	char s[100];
	scanf("%s",s);
	int l=strlen(s);
	int i,j;
	for(i=0;i<l;i++){
		if(s[i+1]=='-'){
			if((s[i]>='0'&&s[i]<='9')&&(s[i+2]>=s[i]&&s[i+2]<='9')){
				if(s[i-1]!='-')printf("%c",s[i]);
				for(j=1;j<=(s[i+2]-s[i]);j++){
					printf("%c",s[i]+j);
				}
				i+=1;
				x[i+1]=1;
			}
			else if((s[i]>='a'&&s[i]<='z')&&(s[i+2]>=s[i]&&s[i+2]<='z')){
				if(s[i-1]!='-')printf("%c",s[i]);
				for(j=1;j<=(s[i+2]-s[i]);j++){
					printf("%c",s[i]+j);
				}
				i+=1;
				x[i+1]=1;
			}
			else if((s[i]>='A'&&s[i]<='Z')&&(s[i+2]>=s[i]&&s[i+2]<='Z')){
				if(s[i-1]!='-')printf("%c",s[i]);
				for(j=1;j<=(s[i+2]-s[i]);j++){
					printf("%c",s[i]+j);
				}
				i+=1;
				x[i+1]=1;
			}
			else{
				printf("%c",s[i]);
			}
		}
		else if(x[i]==0){
			printf("%c",s[i]);
		}
	}
	return 0;
}


