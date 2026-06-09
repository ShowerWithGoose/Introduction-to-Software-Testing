#include <stdio.h>
#include <string.h>
char s[1000005];
char c='0';
int main(){
	fgets(s, sizeof(s), stdin);
	int flag=0;
	for(;flag<=strlen(s)-1;flag++){
		if (s[flag]=='-'){
			if (flag == 0||flag == strlen(s)-1)
				printf("%c",s[flag]);
			else{

				if(s[flag-1]>='a'&&s[flag+1]<='z'&&s[flag-1]<s[flag+1]){
					for (c=s[flag-1]+1;c<s[flag+1];c++){
						printf("%c",c);
					}
				}
				else if(s[flag-1]>='A'&&s[flag+1]<='Z'&&s[flag-1]<s[flag+1]){
					for (c=s[flag-1]+1;c<s[flag+1];c++){
						printf("%c",c);
					}
				}
				else if(s[flag-1]>='0'&&s[flag+1]<='9'&&s[flag-1]<s[flag+1]){
					for (c=s[flag-1]+1;c<s[flag+1];c++){
						printf("%c",c);
					}
				}
				else
					printf("%c",s[flag]);
			}
		}
		else
			printf("%c",s[flag]);	
	}
	printf("\n");
	return 0;
}



