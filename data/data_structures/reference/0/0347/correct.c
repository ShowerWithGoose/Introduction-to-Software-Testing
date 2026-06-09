#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000]={0};
    char c,k;
    int i=0;
    while((c=getchar())!=EOF){
        s[i++]=c;
	}
	for(i=0;i<strlen(s);i++){
		if(s[i]!='-'){
			printf("%c",s[i]);
	    }
		else{
			if(i==0){
				printf("%c",s[i]);
			}
			else{
				if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&(s[i-1]<=s[i+1])){
					for(k=s[i-1]+1;k<s[i+1];k++){
						printf("%c",k);
					}
				}
				else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&(s[i-1]<=s[i+1])){
					for(k=s[i-1]+1;k<s[i+1];k++){
						printf("%c",k);
					}
				}
				else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&(s[i-1]<=s[i+1])){
					for(k=s[i-1]+1;k<s[i+1];k++){
						printf("%c",k);
					}
				}
				else{
					printf("%c",s[i]);
				}
			}
		}
	}
	
	return 0;
}

