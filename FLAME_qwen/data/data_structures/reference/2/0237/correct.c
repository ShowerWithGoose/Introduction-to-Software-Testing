#include <stdio.h>
int main(){
	char a[1000];
	gets(a);
	char s[1000];
	int i,l,t,stop;
	for(i=0,l=0;a[i]!='\0';i++){
		if(a[i]==' '){
			continue;
		}
		s[l]=a[i];
		l++;
	}
	stop=l-1;
	//printf("%s",s);
	int j[100],n,fu=0;
	j[0]=1;
	//i s[i]   t j[t]各项结果 fu==1 *    fu==2 /  fu==0第一个数 
	
	for(i=0,t=0,n=0,fu=0;s[i]!='\0';i++){
		 
			if(s[i]>='0'&&s[i]<='9'){
				n=n*10+s[i]-'0';
				continue;
			}
			if(fu==0||fu==1){
				j[t]=j[t]*n;
				n=0;
			}
			if(fu==2){
				j[t]=j[t]/n;
				n=0;
			}
			if(s[i]=='*'){
				fu=1;
				continue;
			}
			if(s[i]=='/'){
				fu=2;
				continue;
			}
			if(s[i]=='+'){
				t++;
				j[t]=1;
				fu=0;
				continue;
			}
			if(s[i]=='-'){
				t++;
				j[t]=-1;
				fu=0;
				continue;
			}
			if(s[i]=='='){
				break;
			}
		
	}
	int result=0;
	for(i=0;i<=t;i++){
		result=result+j[i];
	}
	printf("%d",result);
	
	

	return 0;
}

