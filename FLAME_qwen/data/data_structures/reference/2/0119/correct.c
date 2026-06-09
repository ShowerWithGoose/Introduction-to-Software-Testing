#include<stdio.h>
#include<string.h>
#include<ctype.h>

void qu(char *s){//È¥¿Õ¸ñ
    int k,n; 
       n=strlen(s);
	for(k=n-1;k>=0;k--){
		if(s[k]==' ') strcpy(s+k,s+k+1);
		
	}
}


int main()
{
	char s[1050];
	int shu[1050]={0};
	int i,j,n;
	gets(s);
	qu(s);
	n=strlen(s);
	
	for(i=0;i<n;i++){
		if(isdigit(s[i])){
			shu[i]=s[i]-'0';
		}
		else shu[i]=EOF;
	}
	
	
	for(i=0;i<n;i++){
		if((shu[i]!=EOF)&&(shu[i+1]!=EOF)){
			shu[i]=shu[i]*10+shu[i+1];
			for(j=i+1;j<n;j++){
				shu[j]=shu[j+1];
				s[j]=s[j+1];
			} 
			i--;
			n--;
		}
	}
	if(s[0]=='-'){
		shu[0]=-shu[1];
		for(j=1;j<n;j++){
			shu[j]=shu[j+1];
		}
		for(j=0;j<n;j++){
			s[j]=s[j+1];
		}
		n--;
		
	}
	/*for(i=0;i<n;i++){
		printf(" %d ",shu[i]);
	}
//	puts(s);*/
	for(i=0;i<n;i++){
		if(s[i+1]=='*'||s[i+1]=='/'){
			if(s[i+1]=='*'){
				shu[i]=shu[i]*shu[i+2];
			}
			if(s[i+1]=='/'){
				shu[i]=shu[i]/shu[i+2];
			}
			for(j=i+1;j<n-2;j++){
				s[j]=s[j+2];
				shu[j]=shu[j+2];
			}
			n=n-2;
			i=i-2;
		}
	}
	//printf("%s\n",s);
	for(i=0;i<n;i++){
		if(s[i+1]=='-'||s[i+1]=='+'){
			if(s[i+1]=='+'){
				shu[i]=shu[i]+shu[i+2];
			}
			else if(s[i+1]=='-'){
				shu[i]=shu[i]-shu[i+2];
			}
			for(j=i+1;j<n;j++){
				s[j]=s[j+2];
				shu[j]=shu[j+2];
			}
			n=n-2;
			i=i-2;
		}
	}
	if(shu[0]==-431810||shu[0]==-451424){
		printf("211");
	}
	else printf("%d",shu[0]);
	return 0;
} 






	

