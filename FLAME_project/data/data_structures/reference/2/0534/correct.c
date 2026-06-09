#include<stdio.h>

char suanshi[10001],fuhao[1001];
int shuzhi[1001];
int main()
{
	int i=0,answer=0,flag=0,j=0,k=0;
	gets(suanshi);
	//puts(suanshi);
	while(suanshi[i]!='='){
		if(suanshi[i]<='9'&&suanshi[i]>='0'){
			shuzhi[j]=shuzhi[j]*10+(suanshi[i++]-'0');
		}
		else if(suanshi[i]=='+'||suanshi[i]=='-'||suanshi[i]=='/'||suanshi[i]=='*'){
			fuhao[k++]=suanshi[i++];
			j++;
		}
		else i++;
	}
	for(i=0;i<k;++i){
		if(fuhao[i]=='/'){
			shuzhi[i+1]=shuzhi[i]/shuzhi[i+1];
			shuzhi[i]=0;
		}
		else if(fuhao[i]=='*'){
			shuzhi[i+1]=shuzhi[i]*shuzhi[i+1];
			shuzhi[i]=0;
		}
	}
	answer=shuzhi[0];
	for(i=0;i<k;++i){
		if(fuhao[i]=='+'){
			flag=0;
		}
		if(fuhao[i]=='-'){
			flag=1;
		}
		if(flag==0) answer+=shuzhi[i+1];
		if(flag==1) answer-=shuzhi[i+1];
	}
	//for(i=0;i<=j;i++) printf("%d\n",shuzhi[i]);
	//puts(fuhao);
	printf("%d",answer);
	return 0;
}



