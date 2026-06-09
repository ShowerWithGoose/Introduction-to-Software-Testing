#include<stdio.h>
#include<string.h>

int chulishuzi(int x[],int k)
{
	int j;
	int sum=0;
	int weishu=1;
	for(j=k-1;j>=0;j--){
		if(x[j]==0){
			weishu*=10;
			continue;
		}
		sum+=x[j]*weishu;
		weishu*=10;
	}
	return sum;
}
char s[1010];
int chengfadeshu[100];
int jiafa[100];
int main()
{
	int i,j,k,b;
	int l=0,r=0;
	int n,m,x[100];
	gets(s);
	char a[100];
	int tmp=1; 
	int markcheng=0,markchu=0;	
	int count =0;
	int mark=0;
	int m1=0;
	int cheng1=0,chu1=0;
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			for(j=i;s[j]>='0'&&s[j]<='9';j++){
				x[k++]=s[j]-'0';
			}
			i=j-1;//有待修改 
			chengfadeshu[l++]=chulishuzi(x,k);
			k=0; 
			memset(x,0,sizeof(x[0]));
			if(markcheng==1) {
				tmp*=chengfadeshu[l-1];
				if(tmp==1) cheng1=1;
				markcheng=0;
			}
			if(markchu==1){
				tmp=tmp/chengfadeshu[l-1];
				if(tmp==1) chu1=1;
				markchu=0;mark=1;
			}
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='=') {
			if(tmp==1&&mark!=1) jiafa[r++]=chengfadeshu[l-1];
			else{
				mark=0;
				jiafa[r++]=tmp;
				tmp=1;
			}
		}
		else if(s[i]=='/'||s[i]=='*' ){
				if(s[i]=='*')  {
					markcheng=1;
					if(tmp==1&&cheng1!=1){
						tmp=chengfadeshu[l-1];
					} 
					else if(tmp==1&&cheng1==1){
						cheng1=0;
					}
				}
				else{
					markchu=1;
					if(tmp==1&&chu1!=1){
						tmp=chengfadeshu[l-1];
					} 
					else if(tmp==1&&chu1==1){
						chu1=0;
					}
				}//有待修改； 
		}
		else continue;
	}
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='+'||s[i]=='-'){
			m1=1;
			break;
		}
	}
	int tmp1=1;
	j=0;
	if(m1==0){tmp1=chengfadeshu[j++];
		for(i=0;s[i]!='\0';i++){
			if(s[i]=='*'){
				tmp1*=chengfadeshu[j++];
			}
			else if(s[i]=='/'){
				tmp1/=chengfadeshu[j++];
			}
		}
		printf("%d",tmp1);
		return 0;
	}
	int sum=jiafa[0];
	int judge=0;
	for(i=strlen(s)-1;i>0;i--){
			if(s[i]=='+'){
			sum+=jiafa[--r];//printf(" w%dw ",sum);
		}
		else if(s[i]=='-'){
			sum-=jiafa[--r];//printf(" r%dr ",sum);
		}
		
	}
	printf("%d",sum);
	return 0;
}



