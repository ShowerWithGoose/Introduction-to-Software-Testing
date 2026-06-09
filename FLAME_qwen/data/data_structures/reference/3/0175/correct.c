#include <stdio.h>
#include <string.h>
int main()
{   
	char s[1000];
	char *p=NULL;
	int i,t,num=0;
	scanf("%s",s);
	p=strchr(s,'.');
	t=p-s;
	if(p==NULL){
		puts(s);
	}
	else if(p-s>1){
		printf("%c",s[0]);
		printf(".");
		for(i=1;i<t;i++){
			printf("%c",s[i]);
		}
		for(i=t+1;i<=strlen(s)-1;i++){
			printf("%c",s[i]);
	    }
	    printf("e%d",t-1);
	}
	else if(p-s==1){
		if(s[0]!='0'){
			printf("%s",s);
			printf("e0");
		}
		else{
			
			for(i=0;i<=strlen(s)-1;i++){
				if(s[i]!='0'&&s[i]!='.'){
				printf("%c",s[i]);break;
			    }
			}
			if(i!=strlen(s)-1){
				printf(".");
			    num=i;i++;
				for(;i<=strlen(s)-1;i++){
				printf("%c",s[i]);
			    }
				printf("e-%d",num-1);return 0;
			}
			printf("e-%d",strlen(s)-2);
			
		}
	}
	return 0;
	
}


