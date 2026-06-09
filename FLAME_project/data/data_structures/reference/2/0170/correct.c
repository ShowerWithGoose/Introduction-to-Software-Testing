#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char sPre[10000],sPost[10000];
char *pmulti,*pdiv,*pplus,*pminus,*pminus2,*ptmp;

void calculate(char*);
int main()
{

	int i=0,j=0,tmpR;
	fgets(sPre,10000,stdin);
	for(i=0;i<strlen(sPre);i++){
		if(sPre[i]!=32) sPost[j++]=sPre[i]; //È¥µô¿Õ¸ñ 
	}
	//puts(sPost);
	pmulti=strchr(sPost,'*');
	pdiv=strchr(sPost,'/');
	while(pmulti!=NULL&&pdiv!=NULL){
		if(pmulti-pdiv>0) calculate(pdiv);
		else calculate(pmulti);
		
		pmulti=strchr(sPost,'*');
		pdiv=strchr(sPost,'/');
	}
	while((pmulti=strchr(sPost,'*'))!=NULL)
		calculate(pmulti);
	while((pdiv=strchr(sPost,'/'))!=NULL)
		calculate(pdiv);
		
	pplus=strchr(sPost,'+');
	pminus=strchr(sPost,'-');
	while(pplus!=NULL&&pminus!=NULL&&strrchr(sPost,'-')-sPost!=0){
		if(pplus-pminus>0&&pminus-sPost!=0) calculate(pminus);
		else calculate(pplus);
		
		pplus=strchr(sPost,'+');
		pminus=strchr(sPost,'-');
	}
	while((pplus=strchr(sPost,'+'))!=NULL)
		calculate(pplus);
	while((pminus=strrchr(sPost,'-'))!=NULL&&pminus-sPost!=0){
		if((pminus2=strchr(sPost,'-'))-strchr(pminus2+1,'-')==1){
			*(strchr(pminus2+1,'-'))='0';
			*strchr(pminus2,'-')='+';
		}
		if((pminus2=strchr(sPost,'-'))-sPost!=0){
			if((pminus2=strchr(sPost,'-'))-strchr(pminus2+1,'-')==1){
				*(strchr(pminus2+1,'-'))='0';
				*strchr(pminus2,'-')='+';
			}
			calculate(pminus2);
		}
		
		else if((pminus2=strchr(sPost,'-'))-sPost==0){
			if(pminus2-strchr(pminus2+1,'-')==-1){
				*(strchr(pminus2+1,'-'))='+';
				*strchr(pminus2,'-')='0';
			}
			calculate(pminus);
		}
	}
		
	for(i=0;sPost[i]!='='&&i<strlen(sPost);i++){
		printf("%c",sPost[i]);
	}
	
	
	return 0;
}
void calculate(char* p)
{
	char tmpSign=*p,sTmp[10000],stmpr[1000];
	int i=0,j=0,flg=0,tmpR,tmpC;	
	for(j=2;flg==0;j++){
		if(*(p+j)>'9'||*(p+j)<'0') flg=1;
	}
	flg=0;
	for(i=1;i<=p-sPost&&flg==0;i++){
		if(*(p-i)>'9'||*(p-i)<'0') flg=1;
	}
	if(strchr(sPost,'-')-sPost==0) flg=2;
	if(flg==1){
		if(tmpSign=='*') tmpR=atoi(p-i+2)*atoi(p+1);
		else if(tmpSign=='/') tmpR=atoi(p-i+2)/atoi(p+1);
		else if(tmpSign=='-') tmpR=atoi(p-i+2)-atoi(p+1);
		else if(tmpSign=='+') tmpR=atoi(p-i+2)+atoi(p+1);
	}
	else if(flg==0){
		if(tmpSign=='*') tmpR=atoi(p-i+1)*atoi(p+1);
		else if(tmpSign=='/') tmpR=atoi(p-i+1)/atoi(p+1);
		else if(tmpSign=='-') tmpR=atoi(p-i+1)-atoi(p+1);
		else if(tmpSign=='+') tmpR=atoi(p-i+1)+atoi(p+1);
	}
	else{
		if(tmpSign=='+') tmpR=atoi(sPost)+atoi(p+1);
		else tmpR=atoi(sPost)-atoi(p+1);
	}	
	
	strcpy(sTmp,p+j-1);
	//printf("%d\n",atoi(p+1));
	if(flg==1) *(p+2-i)='\0';
	else *(p+1-i)='\0';
	//printf("%s\n",p+2-i);
	//itoa(tmpR,stmpr,10);
	tmpC=tmpR;
	if(tmpR<0){
		tmpR=-tmpR;
		tmpC=tmpR;
		stmpr[0]='-';
		for(j=0;tmpC>0;j++){
			tmpC/=10;
		}
		for(i=j;i>=1;i--){
			stmpr[i]=tmpR%10+'0';
			tmpR/=10;
		}
	}
	else if(tmpR==0){
		stmpr[0]='0';
	}
	else {
		for(j=0;tmpC>0;j++){
			tmpC/=10;
		}
		for(i=j-1;i>=0;i--){
			stmpr[i]=tmpR%10+'0';
			tmpR/=10;
		}
	}
	
	strcat(sPost,stmpr);
	strcat(sPost,sTmp);
	//printf("%s\n",sPost);
	memset(stmpr,'\0',strlen(stmpr));
}

