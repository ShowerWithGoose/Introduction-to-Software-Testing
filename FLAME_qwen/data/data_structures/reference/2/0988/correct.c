
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6
int main(){
	char ch,s[1005];
	gets(s);
	int i,t,j=0,l=strlen(s);
	for(i=0;s[i]!='\0';i++)
		if(s[i]!=' ')
			s[j++]=s[i];
	s[--j]='\0';
	j=0;
	int x1,x2,num1,num2,ans,weishu;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='*'&&s[i]!='/'){
			s[j++]=s[i];
		}else{
			int flag=0;
			if(s[i]=='*') flag=1; 
			num1=0; num2=0;
			x1=j-1; x2=i+1;
			while(s[x1]>='0'&&s[x1]<='9'&&x1>=0) x1--;
			for(t=x1+1;t<j;t++) num1=num1*10+s[t]-'0';
			while(s[x2]>='0'&&s[x2]<='9'&&s[x2]!='\0') x2++;
			for(t=i+1;t<x2;t++) num2=num2*10+s[t]-'0';
			ans=flag? num1*num2 : num1/num2;
			weishu=0;
			while(ans/pow(10,weishu)>9) weishu++;
			j=x1+1; i=x2-1;
			for(t=weishu;t>=0;t--) {
				s[j++]=((int)(ans/pow(10,t)))%10+'0';
			}
		}
	}
	s[j]='\0'; 
	int flag=1; ans=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='+'&&s[i]!='-'&&flag==1){
			ans=ans*10+s[i]-'0';
		}else{
			flag=0;
			num2=0; x2=i+1;
			while(s[x2]>='0'&&s[x2]<='9') {
				num2=num2*10+s[x2]-'0';
				x2++;
			}	
			if(s[i]=='+'){
				ans+=num2;
			}else ans-=num2;
			i=x2-1;
		}
	}
	printf("%d",ans);
	return 0;
}





