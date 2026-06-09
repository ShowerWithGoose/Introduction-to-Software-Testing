#include<stdio.h>

int main(){
	char s[100000];
	int x[100000]={0};//记录数字 
	int y[100000]={0};//记录符号 
	int i=0,j=0,k=0;
	scanf("%c",&s[i]);
	while(s[i]!='='){
		i++;
		scanf("%c",&s[i]);
		if(s[i]==32)i--;
	}
//	printf("%s\n",s);
	i=0;
	while(s[j]!='='){
		if(s[j]==32){
			j++;
			continue;
		} 
		else if(s[j]>='0'&&s[j]<='9'){
			while((s[j]>='0'&&s[j]<='9')||s[j]=='\0'){
				if(s[j]=='\0'){
					j++;
					continue;
				}
				x[i]=x[i]*10+(s[j]-'0');
				j++;
			}
			i++;
		}
		else {
			if(s[j]=='+')y[k]=1;
			if(s[j]=='-')y[k]=2;
			if(s[j]=='*')y[k]=3;
			if(s[j]=='/')y[k]=4;
			k++;
			j++;
		}
	}
//	for(j=0;j<i;j++){
//		printf("%d\n",x[j]);
//	}
	int ans=x[0],test=0;
	for(j=1,k=0;j<i;j++){
		if(y[k]>2){//乘除法 
			while(y[k]>2){
					if(y[k]==3){
						ans*=x[j++];
					}
					else ans/=x[j++];
					k++;
			}j--; 
		}
		else if(y[k]==1){//加法 
			if(y[k+1]>2){
				test=x[j];
				while(y[k+1]>2){
					if(y[k+1]==3){
						test*=x[++j];
					}
					else test/=x[++j];
					k++;
				}
				ans+=test;
				k++;
			}
			else{
				ans+=x[j];
				k++;
			}
		}
		else if(y[k]==2){//减法 
			if(y[k+1]>2){
				test=x[j];
				while(y[k+1]>2){
					if(y[k+1]==3){
						test*=x[++j];
					}
					else test/=x[++j];
					k++;
				}
				ans-=test;
				k++;
			}
			else{
				ans-=x[j];
				k++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

