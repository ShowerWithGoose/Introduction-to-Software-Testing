#include<stdio.h>
#include<string.h>
char s[10000];
int a[10000],b[10000];
int main(){
	int sum=0,i=0,j=0,k=0,flag=0,len=0;
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]!=' '&&s[i]!='='){
			while(s[i]>='0'&&s[i]<='9'){
				a[j]*=10;
				a[j]+=s[i]-'0';
				i++;
				flag=1;
			}
			if(flag==1){
				i--;
				flag=0;
			}
			if(s[i]=='*'){
			a[j]=-1;
		}else if(s[i]=='/'){
			a[j]=-2;
		}else if(s[i]=='+'){
			a[j]=-3;
		}else if(s[i]=='-'){
			a[j]=-4;
		}
		j++;
		}
	}
	for(i=0;i<j;i++){
		if(a[i]!=-1&&a[i]!=-2){
			b[k]=a[i];
		}else if(a[i]==-1){
			k--;
			b[k]*=a[i+1];
			i++;
		}else{
			k--;
			b[k]/=a[i+1];
			i++;
		}
		k++;
	}
	sum=b[0];
	for(j=1;j<k;j++){
		if(b[j]==-3){
			sum+=b[j+1];
		}else if(b[j]==-4){
			sum-=b[j+1];
		}
	}
	printf("%d",sum);
	return 0;
} 

