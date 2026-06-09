#include<stdio.h>
#include<string.h>
int main(){
	char ch[1000];
	scanf("%s",ch);
	int len=strlen(ch);
	int a=0,b=0,c=0,i;
	for(i=0;i<len&&ch[i]!='.';i++){
		if(ch[i]!=0)a=a*10+ch[i]-'0';
	}int j=i;	int k=0;//标记下.的位置 
	int start=0,end=len-1;
	for(i=0;i<=len-1;i++){
		if(ch[i]!='0'){
			start=i;
			break;
		} 
		else if(ch[i+1]=='.')i++;
	}
	for(i=len-1;i>=0;i--){
		if(ch[i]!='0'){
			end=i;
			break;
		} 
		else if(ch[i-1]=='.')i--; 
	}
	if(ch[start]=='0'&&ch[end]=='0')printf("0");
	else{
		printf("%c",ch[start]);
		for(i=start+1;i<=end;i++){
			if(i==start+1)printf(".");
			if(i!=j)printf("%c",ch[i]);	
		}
		if(start<j)c=j-start-1;
		else c=j-start;
		printf("e%d",c);
	}
	return 0;
}

