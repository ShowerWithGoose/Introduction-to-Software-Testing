#include<stdio.h>
#include<ctype.h>
char s[1005],s1[1005];
int cal(int i);
int main(){
	gets(s);
	int i,j,res=0,ans=0,plus=1,tmp=0;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=' ')
		s1[j++]=s[i];
	}
	s1[j]='\0';
	for(i=0;s1[i]!='=';i++){
		if(s1[i]=='*'||s1[i]=='/'){
			i=cal(i);
		}
	}
	for(i=0;s1[i]!='='&&s1[i];i++){
		while(isalnum(s1[i])){
			tmp*=10;
			tmp+=s1[i]-'0';
			i++;
		}
		ans+=tmp*plus;
		if(s1[i]=='-')
		plus=-1;
		else if(s1[i]=='+')
		plus=1;
		else
		plus=0;
		tmp=0;
	}
	printf("%d\n",ans);
	return 0;
}
int cal(int i){
	int k=i-1,l=i+1,end,head;
	int alnum1=0,alnum2=0,res,pow=1;
	while(k>=0&&isalnum(s1[k])){
		alnum1+=(s1[k]-'0')*pow;
		k--;
		pow*=10;
	}
	pow=1;
	while(s1[l]&&isalnum(s1[l])){
		alnum2*=10;
		alnum2+=s1[l]-'0';
		l++;
	}
	head=k+1;
	if(s1[i]=='*')
		res=alnum1*alnum2;
	else if(s1[i]=='/')
		res=alnum1/alnum2;
	int tmp=res,cnt=0;
	while(tmp){
		cnt++;
		tmp/=10;
	}
	k+=cnt;
	end=k+1;
	while(res){
		s1[k]=res%10+'0';
		res/=10;
		k--;
	}
	while(s1[l]){
		s1[end++]=s1[l++];
	}
	s1[end]='\0';
	return head;
}



