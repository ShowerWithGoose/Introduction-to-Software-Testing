#include<stdio.h>
#include<string.h>
int main(){
	char s[105]="",str[105]="";
	int cnt1=0,cnt2=0,k=0,i,flag=0;
	scanf("%s",s);
		for(i=0;i<strlen(s);i++){
		if(s[i]=='.') break;
	}
	
	if(s[0]=='-'){
		flag=1;
	}
	
	cnt1=i;
	for(i=0;i<strlen(s);i++){
		if(s[i]!='0'&&s[i]!='.'&&s[i]!='-') break;
	}
	cnt2=i;
	//如果cnt2>=2，小数小于1 
	for(;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			str[k]=s[i];
			k++;
		}
	}
	if(flag==1) printf("-");
	printf("%c",str[0]);
	if(strlen(str)!=1) printf(".");
	for(k=1;k<strlen(str);k++){
		printf("%c",str[k]);
	}
	printf("e");
	if(cnt2>=2) printf("%d",1-cnt2);
	else printf("%d",cnt1-1);
	return 0;
}



