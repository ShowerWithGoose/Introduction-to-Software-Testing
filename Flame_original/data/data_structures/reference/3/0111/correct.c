#include<stdio.h>
#include<string.h>
char s[105];
int main(){
	int i,j,k;
	int a=0,b=0,c=0;
	int len;
	scanf("%s",&s);
	len =strlen(s);
	//测出0个数和有无小数点
	for(i=0;i<len;i++){
		if(s[i]=='0')a++;
		if(s[i]=='.')b=i;
	}
	if(a==len-2&&b!=0){printf("%c",s[len-1]);
	printf("e-");printf("%d",a);return 0;
	}
	if(a==len-1&&b==0){printf("%c",s[0]);
	printf("e");printf("%d",a);return 0;
	}
	if(b==0){
		for(i=0;i<len;i++){
		if(i==1)printf(".");
		printf("%c",s[i]);
	    }
	    printf("e");printf("%d",len-1);
	    return 0;
    }
    if(b!=0&&s[0]!='0'){
    	for(i=0;i<len;i++){
		if(i==1)printf(".");
		if(i==b)i++;
		printf("%c",s[i]);
	    }
	    printf("e");printf("%d",b-1);
	    return 0;
    }
    if(s[0]=='0'&&s[1]=='.'){
    	for(i=2;i<len;i++){
    		if(s[i]!='0'){
    			c=i;
    			break;
    		}
    	}
    	for(i=c;i<len;i++){
    		if(i==c+1)printf(".");
			printf("%c",s[i]);
    	}
    	printf("e-");printf("%d",c-1);
    }
	return 0;
} 



