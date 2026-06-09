#include<stdio.h>
#include<string.h>
int main(){
	char equation[200],equation2[200],symbol[100],flag='!';
	int num[100],i,j,k,ans=0;
	memset(num,0,sizeof(num));
	gets(equation);
	for(i=0,j=0;equation[i]!='=';i++){
		if(equation[i]!=' ')equation2[j++]=equation[i];
	}
	equation2[j]='\0';
	for(i=0,j=0,k=0;equation2[i]!='\0'; ){
		if((equation2[i]<'0'||equation2[i]>'9')&&equation2[i]!='=')
			symbol[k++]=equation2[i++];
		else if(equation2[i]>='0'||equation2[i]<='9'){
			num[j]=equation2[i]-'0';
			while(equation2[i+1]>='0'&&equation2[i+1]<='9'){
				num[j]=num[j]*10+(equation2[++i]-'0');
			}
			j++;i++;
		}
	}
	symbol[k]='\0';
	for(i=0;i<=k;i++){
		if(symbol[i]=='*'){
			if(i!=0&&symbol[i-1]=='-')flag='-';
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
			(flag=='-'?(symbol[i]='-'):(symbol[i]='+'));
			flag='!';
		}
		else if(symbol[i]=='/'){
			if(i!=0&&symbol[i-1]=='-')flag='-';
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
			(flag=='-'?(symbol[i]='-'):(symbol[i]='+'));
			flag='!';
		}
	}
	ans=num[0];
	for(i=0;i<=k;i++){
		if(symbol[i]=='+'){
			ans+=num[i+1];
		}
		else if(symbol[i]=='-'){
			ans-=num[i+1];
		}
	}
	printf("%d",ans);
	return 0;
}

