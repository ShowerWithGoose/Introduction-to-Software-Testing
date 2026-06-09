#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char s1[100];
char s[100];

void s12s(char *s1,char*s){//去掉空格 
	int i=0,j=0;
	int len=strlen(s1);
	for(i=0;i<len;i++){
		if(s1[i]!=' '){
			s[j]=s1[i];j++;
		}
	}
}

int cal_block(int start,int end){//start end分别表示一段只有乘除法的算式里的第一个、最后一个数字 
	int t=0;
	int j=start;
	while(s[j]>='0'&&s[j]<='9'){
		t*=10; 
		t+=(s[j]-'0');
		j++;
	}
	if(j==end)return t;
	
	int ans=t;
//	printf("t is %d\n",t);
	int i=j+1;
	while(i<=end){//每次i都停留在下一个数字那里； 
		t=0;
		int flag=i-1;//flag则在上一个符号那里 
		while(s[i]>='0'&&s[i]<='9'&&i<=end){
			t*=10; 
			t+=(s[i]-'0');
			i++;
		}
		if(s[flag]=='*'){
			ans*=t;
			i++;
		} 
		else if(s[flag]=='/'){
			ans/=t;
			i++;
		}
	}
//	printf("ans is %d\n",ans);
	return ans; 

}

int main(){
	gets(s1);
	s12s(s1,s);//去空格 

	int len_real=strlen(s);
	int flag_sta=0,flag_end;
	
	int res=0;
	for(int i=0;i<len_real;i++){
		if(s[i]=='+'||s[i]=='-'||s[i]=='='){
			flag_end=i-1;
			int tem=cal_block(flag_sta,flag_end);
			if(flag_sta==0){
				res=tem;flag_sta=flag_end+2;continue;
			} 
			if(s[flag_sta-1]=='+')res+=tem;
			else if(s[flag_sta-1]=='-')res-=tem;
			flag_sta=flag_end+2;
		}
	}
	printf("%d",res); 
	return 0;
}


