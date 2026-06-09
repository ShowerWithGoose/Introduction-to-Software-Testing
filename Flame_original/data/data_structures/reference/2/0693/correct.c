#include <stdio.h>
#include <string.h>
int main()
{
	char ch[100],newch[100],fuhao[100];
	int num[100]={0};
	int i,l,j=0,newl,k,z=0,y=0,lfuhao,ans=0,x=0;
	gets(ch);
	l=strlen(ch);
	for(i=0;i<l;i++){
		if(ch[i]!=' '){
			newch[j]=ch[i];
			j++;
		}
	}
	newl=strlen(newch); //去除空格 
	for(j=0;j<newl;j=j+k){
		k=0;
		if(newch[j]>=48&&newch[j]<=57){
			num[z]=newch[j]-48;
			k=1;
			if(newch[j+1]>=48&&newch[j+1]<=57){
			
	     	for(k=1;newch[j+k]>=48&&newch[j+k]<=57;k++){
			num[z]=num[z]*10+newch[j+k]-48;
		    }
		}
		z++;
		}
		else{
			fuhao[y]=newch[j];
			y++;
			k=1;
		}
	
	
		}
	lfuhao=y; //用两个数组分别存放符号和数字 
	
	for(y=0;y<lfuhao;y++){
		if(fuhao[y]=='*'){
		num[y+1]=num[y]*num[y+1];
		num[y]=0;
		if(y==0){
			fuhao[y]='+';
		}
		else{
		fuhao[y]=fuhao[y-1];
		}
			
		
		}
		if(fuhao[y]=='/'){
			num[y+1]=num[y]/num[y+1];
			num[y]=0;
			if(y==0){
			fuhao[y]='+';
		}
		else
		fuhao[y]=fuhao[y-1];	
		
		}
	}  //进行乘除运算 
	
	ans=num[0];
	for(y=0;y<lfuhao;y++){
		if(fuhao[y]=='+'){
			
		   ans=ans+num[y+1];
		}
		if(fuhao[y]=='-'){
		
		   ans=ans-num[y+1];
		}
	}
	printf("%d",ans);
	return 0;
}




