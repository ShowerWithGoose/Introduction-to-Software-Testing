#include<stdio.h>
#include<string.h>
#include<math.h>
#define M 10000
int cal(int x,int y,char c){
	if(c=='+') return x+y;
	else if(c=='-') return x-y;
	else if(c=='*') return x*y;
	else return x/y;
} 
int isnum(char c){
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int on(char s[],int i){
	int sum=0,k;
	for( k=i;isnum(s[k]);k++);
	k--;
	for(int j=k,cnt=0;j>=i;j--,cnt++){
		sum+=(s[j]-'0')*pow(10,cnt);
	}
	return sum;
}
int pre(char c){
	if(c=='+'||c=='-') return 1;
	else if(c=='*'||c=='/') return 2;
	else return 0;
}
char s[M],op[M];
int num[M],tmp[M],tmp_op[M];


int main(){
	gets(s);
	int numc=0,opc=0;
	for(int i=0;i<strlen(s);){
		if(isnum(s[i])){
			num[numc++]=on(s,i);
			while(isnum(s[++i]));//读完一整个数，避免重复读数 
		}
		else if(s[i]!='='&&s[i]!=' '){
			op[opc++]=s[i];
			i++;
		}
		else i++;
	}//读取数字与运算符

	int cnt1=0,cnt2=0;
	for(int i=0;i<opc-1;i++){
		if(pre(op[i])==2) cnt1++;
		else if(pre(op[i])==1) cnt2++;
		else continue;
	}//查看是否只有单个运算优先级 
	if(opc==0){
		printf("%d",num[0]);
		return 0;
	}//一个数，直接输出 
	if(cnt1==0){
		int ans=0;
		for(int i=0,j=0;i<opc;i++){
		if(j==0){
			ans=cal(num[j],num[j+1],op[i]);
			j+=2;
		}
		else{
			ans=cal(ans,num[j],op[i]);
			j++;
		} 
	}
	printf("%d",ans);
	return 0;
	}//只有加减法 
	int tmpc=0,flag=0;
	for(int i=0;i<opc;i++){
		if(pre(op[i])==2){
			if(flag==0){
				tmp[tmpc++]=cal(num[i],num[i+1],op[i]);
				flag=1;
			}
			else{
				tmpc--;
				tmp[tmpc]=cal(tmp[tmpc],num[i+1],op[i]);
				tmpc++;
			}
		}
		else{
			if(flag==0){
				if(i==0||pre(op[i-1])==1)tmp[tmpc++]=num[i];
				else tmp[tmpc++]=num[i+1];
			}
			else{
				tmp[tmpc]=num[i+1];
				flag=0;
			}
		}
	}
	if(!flag) tmpc++;
	//处理后只剩加减运算
	
	
	if(cnt2==0){
		printf("%d",tmp[0]);
		return 0;
	}//只有乘除运算 
	
	int sum=0;
	for(int i=0,j=0;i<opc&&j<tmpc;i++){
		if(pre(op[i])==1) tmp_op[j++]=op[i];
	}//录入加减运算符
	 
	
	for(int i=0,j=0;i<tmpc-1;i++){
		if(j==0){
			sum=cal(tmp[j],tmp[j+1],tmp_op[i]);
			j+=2;
		}
		else{
			sum=cal(sum,tmp[j],tmp_op[i]);
			j++;
		} 
	}
	printf("%d",sum);
	return 0;
}

