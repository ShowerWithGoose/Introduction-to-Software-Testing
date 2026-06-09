#include <stdio.h>
#include <string.h>
int a1[2000],a2[2000],a3[2000];
int tr1(char []);
int tr2(char []);
int main(){
	char ch[2000],sh[2000],th[1000];
	gets(ch);
	int i,j,k;
	for(i=0,j=0;i<strlen(ch);){
		if(ch[i]!=' '){
			sh[j++]=ch[i++];
		}else{
			i++;
		}
	}
	
	for(i=0,j=0,k=0;i<strlen(sh);i++){
		
		if(sh[i]>='0'&&sh[i]<='9'){
			a1[j]*=10;
			a1[j]+=sh[i]-'0';
		}else{
			j++;
			th[k++]=sh[i];
		}
	}
	
	k=0;j=0;
	a3[0]=a1[0];
	while(th[k]!='='){
		
		if(th[k]=='+'){
			j++;
			a3[j]=a1[k+1];
			
		}else if(th[k]=='-'){
			j++;
			a1[k+1]*=-1;
			a3[j]=a1[k+1];
		}else if(th[k]=='*'){
			a3[j]*=a1[k+1];
		}else if(th[k]=='/'){
			a3[j]/=a1[k+1];
		}
		k++;
	}
	k=0;
	long long ans=0;
	while(k<=j){
		ans+=a3[k];
		k++;
	}
	printf("%lld",ans);
	return 0;
}

