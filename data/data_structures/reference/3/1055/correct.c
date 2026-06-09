#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
char s[1000];
int len;
int i,j,k;
int q;

gets(s);
len=strlen(s);
char *p=NULL;
p=strchr(s,'.');
if(p==NULL){
	for(i=0;i<len;i++){
		printf("%c",s[i]);
	}
}
else if(p-s==1){
	if(s[0]!='0'){
		for(int i=0;i<len;i++){
			printf("%c",s[i]);
		}
		printf("e0");
	}
	else{
		i=2;
		for(i=2;i<len;i++){
			if(s[i]!='0'){
				
				q=i;
				if(q!=len-1){
					break;
				}
			}
		}
		if(q==len-1){
			printf("%c",s[q]);
			printf("e-");
			printf("%d",q-1);
		}
		else{
			printf("%c",s[q]);
			printf(".");
			for(j=q+1;j<len;j++){
				printf("%c",s[j]);
			}
			printf("e-");
			printf("%d",q-1);
		}
	}
}
else{
	printf("%c",s[0]);
	printf(".");
	for(k=1;k<=p-s-1;k++){
		printf("%c",s[k]);
	}
	k=0;
	for(k=p-s+1;k<=len-1;k++){
		printf("%c",s[k]);
	}
	printf("e");
	printf("%d",p-s-1);
}
return 0;
}



