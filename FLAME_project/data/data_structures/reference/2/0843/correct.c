#include<stdio.h>
#include<string.h>
int main(){
	int len,q,i,k,l=1,j,m,n=0,result,o,r=0,count[100]={-1},sum[100]={0},key[100]={0},Sum[100]={0};
	char s[100],c[100];
	gets(c);
	len=strlen(c)-1;
	for(i=0,q=0;i<=len;i++){
		if(c[i]!=' ') s[q++]=c[i];
	}
	len=strlen(s)-1;
	for(i=0,q=1;i<=len;i++){
		if(s[i]=='+'||s[i]=='-'){
			count[q++]=i;
		}
	}
	for(i=0;i<=len;i++){
		if(s[i]=='=')
		count[q]=i;
	}
	q=q-1;
	for(i=0;i<=q;i++){
		l=1;
		for(r=0;r<100;r++){
			key[r]=0;
			if(key[r+1]==0&&key[r+2]==0)break;
		}
		for(k=count[i]+1;k<count[i+1];k++){
			key[0]=count[i];
			if(s[k]=='*'||s[k]=='/'||s[k]=='='){
				key[l]=k;l++;
			}
		}
		while(1){
			for(m=key[n]+1;m<key[n+1]||(key[n+1]==0&&key[n+2]==0);m++){
				if(s[m]=='+'||s[m]=='-'||s[m]=='=') break;
				sum[n]=s[m]-'0'+sum[n]*10;
			}
			n++;
			if(key[n]==0&&key[n+1]==0){
				n=0;
				break;
			}
		}
		Sum[i]=sum[0];
		for(o=1;o<l;o++){
			if(s[key[o]]=='*'){
				Sum[i]*=sum[o];
			}
			if(s[key[o]]=='/'){
				Sum[i]/=sum[o];
			}
		}
		for(r=0;r<100;r++){
			sum[r]=0;
			if(sum[r+1]==0&&sum[r+2]==0)break;
		}	
	}
	result=Sum[0];
	for(i=0,j=1;i<100;i++){
		if(s[count[i]]=='-'){
			result-=Sum[j];
			j++;
		}
		if(s[count[i]]=='+'){
			result+=Sum[j];
			j++;
		}
	}
	printf("%d",result);
	return 0;
}

