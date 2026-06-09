#include <stdio.h>
#include <string.h>
int main(){
	char s[102];
	char c[102];
	gets(s);
	int i,j,k=0;
	int jishu;
	int cnt=0;
	int flag=0;
	int n=0;
	int m=strlen(s);
	for(i=0;i<m;i++){
		if(s[i]=='.')
		jishu=i;
	}
	for(i=jishu+1;i<strlen(s);i++){
		if(s[i]!='0')
		flag++;
	}
	for(i=0;i<jishu;i++){
		if(s[i]!='0')
		cnt++;
	}
	if(flag==0){
	for(i=0;i<jishu;i++){
		printf("%c",s[i]);
	}
	printf("e%d",jishu);
}
    else if(flag==1&&cnt==0){
    	printf("%de-%d",s[m-1]-'0',m-2);
	}
	else if(cnt==0){
		for(i=jishu+1;s[i]!='\0';i++){
			c[k++]=s[i];
		}
		for(i=0;i<k;i++){
			if(c[i]=='0')
			n++;
			else
			break;
		}
		printf("%c.",c[n]);
		for(i=n+1;i<k;i++){
			printf("%c",c[i]);
		}
		printf("e-%d",n+1);
	} 
	else {
		for(i=1;i<strlen(s);i++){
			if(s[i]!='.')
			c[k++]=s[i];
		}
		for(i=k-1;k>0;i--){
			if(c[i]=='0')
			c[i]='\0';
			else
			break;
		}
		printf("%d.",s[0]-'0');
		for(i=0;i<k;i++){
		printf("%c",c[i]);
		}
		printf("e%d",jishu-1);
	}


	return 0;
}

