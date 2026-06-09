#include<stdio.h>
#include<string.h>

char ord[20000],mod[20000],sym[3000];
int length,num[10000],l,tem,w,w2,num2[3000],res;
int main(){
	int j=0,k=0,i=0;
	memset(num2,1,3000);
	gets(ord);
	length=strlen(ord);
	for(i=0,j=0;i<length;i++){
		if(ord[i]!=' '){
			mod[j]=ord[i];
			j++;
		}
		else continue;
	}
	length=strlen(mod);
	for(i=0,j=0;i<length;i++){
		if(mod[i]<='9'&&mod[i]>='0'){
			l++;
		}
		else{
			sym[j]=mod[i];
			tem=0;
			for(w=1,w2=1;l>0;l--,w2++){
				tem+=(mod[i-w2]-'0')*w;
				w*=10;
			}
			num[j]=tem;
			j++;
		}
	}
	num2[0]=num[0];
	for(k=0,i=0;k<j;k++){
		if(sym[k]=='*'){
			num2[i]*=num[k+1];
		}
		else if(sym[k]=='/'){
			num2[i]/=num[k+1];
		}
		else if(sym[k]=='+'){
			i++;
			num2[i]=num[k+1];
		}
		else if(sym[k]=='-'){
			i++;
			num2[i]=num[k+1]*(-1);
		}
		else{
			break;
		}
	}
	for(res=0;i>=0;i--){
		res+=num2[i];
	}
	printf("%d\n",res);
	return 0;
}
