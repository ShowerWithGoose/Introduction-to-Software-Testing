#include<stdio.h>
#include<string.h>
void delete(char s[]);
char s[1024],fuhao[1024],flag[1024],fuhao_gai[1024];
int shu[1024],sum[1024];
int main()
{
	gets(s);
	delete(s);
	int i=0,l=strlen(s),n=0,f=0;
	for(i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[n]=shu[n]*10+s[i]-'0';
		}else{
			fuhao[f++]=s[i];
			n++;
		}
	}
	fuhao[f]='\0';
	n=1;
	int su=0,f_gai=0;
	sum[0]=shu[0];
	for(i=0;fuhao[i]!='\0';i++){
		if(fuhao[i]=='*'){
			sum[su]*=shu[n++];
		}else if(fuhao[i]=='/'){
			sum[su]/=shu[n++];
		}else if(fuhao[i]=='+'){
			sum[++su]=shu[n++];
			fuhao_gai[f_gai++]='+';	
		}else if(fuhao[i]=='-'){
			sum[++su]=shu[n++];
			fuhao_gai[f_gai++]='-';	
		}
		else if(fuhao[i]=='='){
			break;	
		}
	}
	int k,end=sum[0];
//	printf("end=%d ",end);
//	printf("su=%d\n",su);
	for(k=0;k<=su-1;k++){
//		printf("sum[%d]=%d ",k,sum[k]);
		end+=sum[k+1]*((fuhao_gai[k]=='+')?(1):(-1));
	}
//	printf("\nsum[%d]=%d\n",k,sum[k]);
//	for(i=0;i<f_gai;i++)printf("fuhao[%d]=%c",i,fuhao_gai[i]);
	printf("%d",end);


/*	for(i=0;i<f;i++){
		if(fuhao[i]=='*'){
			sum[]=shu[i-1]*shu[i+1];
		}
		else if(fuhao[i]=='/'){
			sum[]=shu[i-1]/shu[i+1];
		}
	}*/
}
void delete(char s[]){
	int i,j;
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=' ')s[j++]=s[i];
	}
	s[j]='\0';
}

