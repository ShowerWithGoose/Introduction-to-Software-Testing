#include<stdio.h>
#include<string.h>
int suan(int,char,int);
int judge(char);
int main ()
{
	char shi[500],fu[500],fuhao[500];
	int a,b,i,j,k,m,len,num[500],number[500],sum=0,flag,n;
	gets(shi);
	memset(num,0,sizeof(num));
	memset(number,0,sizeof(number));
	for( a=0,b=0;shi[a]!='\0';a++)
		if(shi[a]!=' ') shi[b++]=shi[a];
	shi[b]='\0';
	len=strlen(shi);
	
	for( i=0,j=0,k=0,n=0;i<len-1;i++){
		if(judge(shi[i])){
			if (i==0||((!judge(shi[i-1]))&&(shi[i+1]=='='))||((!judge(shi[i-1]))&&(!judge(shi[i+1]))))
				num[j]=shi[i]-'0';
			else num[j]=num[j]*10+shi[i]-'0';
		}
		if(!judge(shi[i])){
			fu[k++]=shi[i];
			n=1;
			j++;
			
		}
	}
	if(!n){
		shi[len-1]='\0';
		puts(shi);
		return 0;
	}
	

	len=strlen(fu);
	flag=0;
	for( i=0,j=0,k=0;i<len;i++){
		if(i==0){
				number[0]=num[0];
			}
		if(fu[i]=='*'||fu[i]=='/'){
			
			number[j]=suan(number[j],fu[i],num[i+1]);
			
		}
		else if(fu[i]=='+'||fu[i]=='-'){
			flag=1;
			j++;
			number[j]=num[i+1];
			fuhao[k++]=fu[i];
		}
	}
	if(flag){
		sum=suan(number[0],fuhao[0],number[1]);
 		for(m=1;m<k;m++){
			sum=suan(sum,fuhao[m],number[m+1]);
		}
	}
	else sum=number[0];
	printf("%d",sum);
	return 0;
}

int suan(int a,char fu,int b){
	if(fu=='+') return a+b;
	if(fu=='-') return a-b;
	if(fu=='*') return a*b;
	if(fu=='/') return a/b;
}

int judge(char shi){
	if(shi=='+'||shi=='-'||shi=='*'||shi=='/')
		return 0;
	return 1;
}


