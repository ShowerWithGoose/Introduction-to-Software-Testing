#include <stdio.h>
#include <string.h>
char s[1000005];
char c='0';
int main(){
	fgets(s, sizeof(s), stdin);
	int i=0;
	for(;i<=strlen(s)-1;i++){
		if (s[i]=='-'){
			if (i == 0||i == strlen(s)-1)
				printf("%c",s[i]);
			else{

				if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){
					for (c=s[i-1]+1;c<s[i+1];c++){
						printf("%c",c);
					}
				}
				else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
					for (c=s[i-1]+1;c<s[i+1];c++){
						printf("%c",c);
					}
				}
				else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
					for (c=s[i-1]+1;c<s[i+1];c++){
						printf("%c",c);
					}
				}
				else
					printf("%c",s[i]);
			}
		}
		else
			printf("%c",s[i]);	
	}
	printf("\n");
	return 0;
}



